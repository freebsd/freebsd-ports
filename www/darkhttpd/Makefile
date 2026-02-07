PORTNAME=	darkhttpd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16
CATEGORIES=	www

MAINTAINER=	henrichhartzer@tuta.io
COMMENT=	Simple, static web server
WWW=		https://unix4lyfe.org/darkhttpd/

LICENSE=	ISCL

USES=		cpe

CPE_VENDOR=	darkhttpd_project

USE_RC_SUBR=	darkhttpd
USE_GITHUB=	yes
GH_ACCOUNT=	emikulic

USERS=	darkhttpd
GROUPS=	darkhttpd

SUB_LIST=	USER=${USERS:[1]} \
		GROUP=${GROUPS:[1]}

PLIST_SUB=	USER=${USERS:[1]} \
		GROUP=${GROUPS:[1]}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${LOCALBASE}/bin

post-install:
	${INSTALL} -d ${STAGEDIR}${WWWDIR}
	${INSTALL} -d ${STAGEDIR}/var/run/darkhttpd

.include <bsd.port.mk>
