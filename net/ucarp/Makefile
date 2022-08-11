PORTNAME=	ucarp
PORTVERSION=	1.5.2.20171201
CATEGORIES=	net

MAINTAINER=	jcpierri@gmail.com
COMMENT=	Userlevel Common Address Redundancy Protocol

LICENSE=	ISC
LICENSE_NAME=	ISC License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
GH_PROJECT=	UCarp
GH_TAGNAME=	4f339d4
GNU_CONFIGURE=	yes

USE_RC_SUBR=	ucarp

PLIST_FILES=	sbin/ucarp

OPTIONS_DEFINE=		SCRIPTS
OPTIONS_DEFAULT=	SCRIPTS

SCRIPTS_DESC=		Install scripts to manage virtual IP
SCRIPTS_PLIST_FILES=	sbin/ucarp-up sbin/ucarp-down

pre-configure:
	@${TOUCH} ${WRKSRC}/config.rpath ${WRKSRC}/ABOUT-NLS

post-install-SCRIPTS-on:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/vip-up.sh ${STAGEDIR}${PREFIX}/sbin/ucarp-up
	${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/vip-down.sh ${STAGEDIR}${PREFIX}/sbin/ucarp-down

.include <bsd.port.mk>
