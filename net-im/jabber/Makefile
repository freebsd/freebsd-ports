# Created by: joe
# $FreeBSD$

PORTNAME=	jabber
PORTVERSION=	1.6.1.1
PORTREVISION=	14
PORTEPOCH=	1
CATEGORIES=	net-im ipv6
MASTER_SITES=	http://download.jabberd.org/jabberd14/ \
		http://download.jabberd.org/jabberd14/old/
DISTNAME=	jabberd14-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMPP/Jabber server daemon

LICENSE=	GPLv2

LIB_DEPENDS=	pth:${PORTSDIR}/devel/pth-hard \
		popt:${PORTSDIR}/devel/popt \
		idn:${PORTSDIR}/dns/libidn \
		expat:${PORTSDIR}/textproc/expat2 \
		tasn1:${PORTSDIR}/security/libtasn1 \
		gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt

OPTIONS_DEFINE= IPV6 MYSQL PGSQL

USE_RC_SUBR=	jabber
USE_GMAKE=	yes
USES=		gettext iconv pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	${PREFIX}/lib/jabber
MAKE_JOBS_UNSAFE=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN5=		jabber.xml.5
MAN8=		jabberd14.8
.endif

JABBER_USER=	jabber
JABBER_UID=	93
JABBER_GROUP=	${JABBER_USER}
JABBER_GID=	${JABBER_UID}
JABBER_ETCDIR=	"${PREFIX}/etc"
JABBER_RUNDIR=	"/var/run/jabberd"
JABBER_SPOOLDIR="/var/spool/jabberd"
JABBER_LOGDIR=	"/var/log/jabberd"

CONFIGURE_ARGS=	--localstatedir=/var \
		--sysconfdir=${JABBER_ETCDIR} \
		--includedir=${PREFIX}/include/jabber \
		--libdir=${PREFIX}/lib/jabber

CPPFLAGS+=	-I${LOCALBASE}/include/pth -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/pth -L${LOCALBASE}/lib -ltasn1 -lgcrypt

SUB_FILES+=	pkg-install pkg-deinstall pkg-message
SUB_LIST+=	JABBER_USER=${JABBER_USER} JABBER_UID=${JABBER_UID} \
		JABBER_GROUP=${JABBER_GROUP} JABBER_GID=${JABBER_GID} \
		JABBER_ETCDIR="${JABBER_ETCDIR}" \
		JABBER_LOGDIR="${JABBER_LOGDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}" \
		JABBER_RUNDIR="${JABBER_RUNDIR}"

DOCS=		AUTHORS ChangeLog INSTALL NEWS README README.SQL README.config \
		README.filespool README.karma README.protocols TODO UPGRADE mysql.sql

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MIPV6}
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
	@${TOUCH} ${PREFIX}/include/jabber/platform-settings
	@${INSTALL_DATA} ${WRKSRC}/jabber.xml.dist ${PREFIX}/etc/jabber.xml.sample
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

.include <bsd.port.mk>
