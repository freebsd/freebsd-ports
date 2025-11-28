PORTNAME=	ucarp
PORTVERSION=	1.5.2.20171201
CATEGORIES=	net

MAINTAINER=	jcpierri@gmail.com
COMMENT=	Userlevel Common Address Redundancy Protocol
WWW=		https://github.com/jedisct1/UCarp

LICENSE=	ISC
LICENSE_NAME=	ISC License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf gettext-tools libtool
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
GH_PROJECT=	UCarp
GH_TAGNAME=	4f339d4
USE_RC_SUBR=	ucarp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

PLIST_FILES=	sbin/ucarp

OPTIONS_DEFINE=		SCRIPTS
OPTIONS_DEFAULT=	SCRIPTS

SCRIPTS_DESC=		Install scripts to manage virtual IP
SCRIPTS_PLIST_FILES=	sbin/ucarp-up sbin/ucarp-down

post-install-SCRIPTS-on:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/vip-up.sh ${STAGEDIR}${PREFIX}/sbin/ucarp-up
	${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/vip-down.sh ${STAGEDIR}${PREFIX}/sbin/ucarp-down

.include <bsd.port.mk>
