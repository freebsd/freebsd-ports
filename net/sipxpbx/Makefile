# Ports collection makefile for: sipxpbx
# Date created: Jan 8, 2007
# Whom: Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	sipxpbx
PORTVERSION=	3.6.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.sipfoundry.org/pub/sipX/3.6/SRC/

MAINTAINER=	durian@shadetreesoftware.com
COMMENT=	sipX PBX - Toplevel sipX port

BUILD_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_cplusplus.so:${PORTSDIR}/www/mod_cplusplus \
		ginstall:${PORTSDIR}/sysutils/coreutils
LIB_DEPENDS=	sipXport:${PORTSDIR}/net/sipxportlib \
		sipXtack:${PORTSDIR}/net/sipxtacklib \
		sipXmedia:${PORTSDIR}/net/sipxmedialib \
		sipXmediaProcessing:${PORTSDIR}/net/sipxmediaadapterlib \
		sipXcall:${PORTSDIR}/net/sipxcalllib \
		sipXcommserver:${PORTSDIR}/net/sipxcommserverlib \
		expat:${PORTSDIR}/textproc/expat2 \
		cgicc:${PORTSDIR}/www/cgicc \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		sipauthproxy:${PORTSDIR}/net/sipxproxy \
		sipregistrar:${PORTSDIR}/net/sipxregistry \
		sipxconfig.sh:${PORTSDIR}/net/sipxconfig \
		sipstatus.sh:${PORTSDIR}/net/sipxpublisher \
		sipXvxml.sh:${PORTSDIR}/net/sipxvxml \
		psql:${PORTSDIR}/databases/postgresql81-client

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env automake:19:env
USE_APACHE=	2.0+
USE_PERL5_RUN=	yes
USE_RC_SUBR=	sipxpbx
GNU_CONFIGURE=	yes
LOCALSTATEDIR=${DESTDIR}/var

.include <bsd.port.pre.mk>
CONFIGURE_ENV+=	wwwdir=${PREFIX}/www/sipX \
		INSTALL=`which ginstall`

.if ${APACHE_VERSION} >= 21
APR_DIR=	${PREFIX}/include/apr-1
APACHE_HOME=	${PREFIX}/share/apache${APACHE_VERSION}
.else
APR_DIR=	${PREFIX}/include/apache2
APACHE_HOME=	${PREFIX}/share/apache2
.endif

CONFIGURE_ARGS+=	--enable-sip-tls \
		--prefix=${PREFIX} \
		--localstatedir=${LOCALSTATEDIR} \
		--with-apache-include=${PREFIX}/${APACHEINCLUDEDIR} \
		--with-apr=${APR_DIR} \
		--with-apache-modules=${PREFIX}/${APACHEMODDIR} \
		--with-apache-home=${APACHE_HOME} \
		--with-mod_cplusplus=${PREFIX}/${APACHEINCLUDEDIR}
SUB_LIST=	LOCALSTATEDIR=${LOCALSTATEDIR} \
		PREFIX=${PREFIX} \
		DESTDIR=${DESTDIR} \
		APACHEMODDIR=${APACHEMODDIR} \
		APACHE_VERSION=${APACHE_VERSION}

SUB_FILES=	pkg-deinstall sipxpbx pkg-message pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/autodel
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/httpd-sipxchange-config.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/keepalive.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/backup-configs.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/restore-configs.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/backup-mailstore.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/restore-mailstore.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/blat
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipx-chkspace.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/voicemail_clean.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/check-fqdn
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/sipXpark/bin/sipxpark.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/src/watchdog/watchdog.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/sipXpresence/bin/sipxpresence.sh.in

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}
	@${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.post.mk>
