PORTNAME=	fakertc
DISTVERSIONPREFIX=	v
DISTVERSION=	3
CATEGORIES=	sysutils

MAINTAINER=	ronald-lists@klop.ws
COMMENT=	Save real-time clock on reboot
WWW=		https://github.com/ronaldklop/fakertc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ronaldklop

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	etc/cron.d/${PORTNAME} etc/rc.d/${PORTNAME}

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
		${INSTALL_DATA} ${WRKSRC}/src/etc/cron.d/${PORTNAME} \
			${STAGEDIR}${PREFIX}/etc/cron.d/
		${INSTALL_SCRIPT} ${WRKSRC}/src/etc/rc.d/${PORTNAME} \
			${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
