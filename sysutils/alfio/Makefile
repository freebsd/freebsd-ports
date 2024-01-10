PORTNAME=	alfio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3
DISTVERSIONSUFFIX=	-bis
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Services manager to choose which services start at boot time
WWW=		https://github.com/lsalvadore/alfio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	lsalvadore

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	etc/rc.d/alfio \
		share/man/man8/alfio.8.gz

do-patch:
	${REINPLACE_CMD} s,%%LOCALBASE%%,${LOCALBASE},g ${WRKSRC}/alfio
	${REINPLACE_CMD} s,%%LOCALBASE%%,${LOCALBASE},g ${WRKSRC}/alfio.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/alfio ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN}	${WRKSRC}/alfio.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
