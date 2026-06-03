PORTNAME=	fakertc
DISTVERSIONPREFIX=	v
DISTVERSION=	3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/ronaldklop/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	Save real-time clock on reboot
WWW=		https://codeberg.org/ronaldklop/fakertc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	etc/cron.d/${PORTNAME} etc/rc.d/${PORTNAME}

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
		${INSTALL_DATA} ${WRKSRC}/src/etc/cron.d/${PORTNAME} \
			${STAGEDIR}${PREFIX}/etc/cron.d/
		${INSTALL_SCRIPT} ${WRKSRC}/src/etc/rc.d/${PORTNAME} \
			${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
