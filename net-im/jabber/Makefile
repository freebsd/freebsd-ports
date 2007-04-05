# New ports collection makefile for:	jabber
# Date created:			5 February 2001
# Whom:				joe
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	1.6.0
PORTEPOCH=	1
CATEGORIES=	net-im ipv6
MASTER_SITES=	http://download.jabberd.org/jabberd14/
DISTNAME=	jabberd14-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	mm@FreeBSD.org
COMMENT=	XMPP/Jabber server daemon

LIB_DEPENDS=	pth.20:${PORTSDIR}/devel/pth-hard \
		popt.0:${PORTSDIR}/devel/popt \
		idn.16:${PORTSDIR}/dns/libidn \
		expat.6:${PORTSDIR}/textproc/expat2

OPTIONS=	IPV6 "Enable IPv6 support" off \
		MYSQL "Build with MySQL support" off \
		PGSQL "Build with PostgreSQL support" off

USE_RC_SUBR=	jabber
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	${TARGETDIR}/lib/jabber

.if !defined(NO_INSTALL_MANPAGES)
MAN5=		jabber.xml.5
MAN8=		jabberd14.8
.endif

JABBER_USER=	jabber
JABBER_UID=	93
JABBER_GROUP=	${JABBER_USER}
JABBER_GID=	${JABBER_UID}
JABBER_ETCDIR=	"${TARGETDIR}/etc"
JABBER_RUNDIR=	"/var/run/jabberd"
JABBER_SPOOLDIR="/var/spool/jabberd"
JABBER_LOGDIR=	"/var/log/jabberd"

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man --localstatedir=/var --enable-ssl \
		--with-ssl-legacy=${OPENSSLBASE} --sysconfdir=${JABBER_ETCDIR} \
		--includedir=${TARGETDIR}/include/jabber \
		--libdir=${TARGETDIR}/lib/jabber

CPPFLAGS+=	-I${LOCALBASE}/include/pth -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/pth -L${LOCALBASE}/lib

SUB_FILES+=	pkg-install pkg-deinstall pkg-message
SUB_LIST+=	JABBER_USER=${JABBER_USER} JABBER_UID=${JABBER_UID} \
		JABBER_GROUP=${JABBER_GROUP} JABBER_GID=${JABBER_GID} \
		JABBER_ETCDIR="${JABBER_ETCDIR}" \
		JABBER_LOGDIR="${JABBER_LOGDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}" \
		JABBER_RUNDIR="${JABBER_RUNDIR}"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README README.SQL README.config \
		README.filespool README.karma README.protocols TODO UPGRADE mysql.sql

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if exists(${LOCALBASE}/include/pth/pthread.h)
IGNORE=	pth with soft syscalls is installed, please reinstall pth from devel/pth-hard
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|\\\$$(localstatedir)/log/jabberd|${JABBER_LOGDIR}|g" \
		-e "s|\\\$$(localstatedir)/spool/jabberd|${JABBER_SPOOLDIR}|g" \
		-e "s|\\\$$(localstatedir)/run/jabberd|${JABBER_RUNDIR}|g" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|@localstatedir@/log/jabberd|${JABBER_LOGDIR}|g" \
		-e "s|@localstatedir@/spool/jabberd|${JABBER_SPOOLDIR}|g" \
		-e "s|@localstatedir@/run/jabberd|${JABBER_RUNDIR}|g" \
		${WRKSRC}/jabber.xml.dist.in
	@${LN} -s ${WRKSRC}/man/jabberd.8.in ${WRKSRC}/man/jabberd14.8.in

post-install:
	@${TOUCH} ${TARGETDIR}/include/jabber/platform-settings
	@${INSTALL_DATA} ${WRKSRC}/jabber.xml.dist ${TARGETDIR}/etc/jabber.xml.sample
.if !defined(NO_INSTALL_MANPAGES)
	@cd ${WRKSRC}/man && make install-man
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
