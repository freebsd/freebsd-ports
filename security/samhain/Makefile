# New ports collection makefile for:	samhain
# Date created:				9 January 2003
# Whom:					lx
#
# $FreeBSD$
#

PORTNAME=	samhain
PORTVERSION=	1.7.5
CATEGORIES=	security
MASTER_SITES=	http://la-samhna.de/samhain/ \
		http://samhain.securecirt.org/
DISTFILES=	samhain_signed-${PORTVERSION}.tar.gz

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	The Samhain Intrusion Detection System

.if defined(WITH_GPG)
BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
.endif

GNU_CONFIGURE= yes
CONFIGURE_ARGS= --enable-login-watch --localstatedir=/var --mandir=${PREFIX}/man

.if defined(TRUSTED_USER)
CONFIGURE_ARGS+=	--enable-identity=${TRUSTED_USER}
.endif
.if defined(WITH_KCHECK)
CONFIGURE_ARGS+=	--with-kcheck
.endif
.if defined(WITH_GPG)
CONFIGURE_ARGS+=	--with-gpg=${PREFIX}/bin/gpg
.endif
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-database=mysql
.endif
.if defined(WITH_POSTGRES)
CONFIGURE_ARGS+=	--with-database=postgresql
.endif
.if defined(CLIENT)
CONFIGURE_ARGS+=	--enable-network=client
PLIST_SUB+=	SAMHAIN="" SETPWD="" YULE="@comment "
MAN5= samhainrc.5
MAN8= samhain.8
.elif defined(SERVER)
CONFIGURE_ARGS+=	--enable-network=server
PLIST_SUB+=	YULE="" SAMHAIN="@comment " SETPWD="@comment "
MAN5= yulerc.5
MAN8= yule.8
.else
PLIST_SUB+=	SAMHAIN="" YULE="@comment " SETPWD="@comment "
MAN5= samhainrc.5
MAN8= samhain.8
.endif

pre-everything::

.if !defined(CLIENT) && !defined(SERVER)
	@${ECHO_MSG} "Building in standalone mode."
	@${ECHO_MSG} "If you wish to enable networked mode, please hit CTRL-C"
	@${ECHO_MSG} "now and make with SERVER=yes or CLIENT=yes."
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${WRKSRC}.tar.gz
	@${RM} ${WRKSRC}.tar.gz ${WRKSRC}.tar.gz.asc

post-install:
.if !defined(SERVER)
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${PREFIX}/etc/rc.d/samhain.sh.sample
.else
	@${CP} ${WRKSRC}/init/samhain.startFreeBSD ${PREFIX}/etc/rc.d/yule.sh.sample
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samhain
	${INSTALL_MAN} ${WRKSRC}/docs/MANUAL-1_7.ps ${PREFIX}/share/doc/samhain
	${INSTALL_MAN} ${WRKSRC}/docs/MANUAL-1_7.html.tar ${PREFIX}/share/doc/samhain
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-client+server.html ${PREFIX}/share/doc/samhain
	${INSTALL_MAN} ${WRKSRC}/docs/HOWTO-samhain+GnuPG.html ${PREFIX}/share/doc/samhain
.endif

install-user:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install-user)

.include <bsd.port.mk>
