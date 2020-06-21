# $FreeBSD$

PORTNAME=	alfio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Services manager to choose which services start at boot time

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	lsalvadore

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	etc/rc.d/alfio \
		man/man8/alfio.8.gz

do-patch:
	${REINPLACE_CMD} s,%%LOCALBASE%%,${LOCALBASE},g ${WRKSRC}/alfio
	${REINPLACE_CMD} s,%%LOCALBASE%%,${LOCALBASE},g ${WRKSRC}/alfio.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/alfio ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN}	${WRKSRC}/alfio.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
