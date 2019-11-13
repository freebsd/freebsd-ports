# $FreeBSD$

PORTNAME=	alfio
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Services manager to choose which services start at boot time

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes

PLIST_FILES=	etc/rc.d/alfio \
		man/man8/alfio.8.gz

pre-install:
	${GZIP_CMD}	${WRKSRC}/alfio.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/alfio ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN}	${WRKSRC}/alfio.8.gz ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
