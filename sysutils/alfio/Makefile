# $FreeBSD$

PORTNAME=	alfio
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Services manager to choose which services start at boot time

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	etc/rc.d/alfio \
		man/man8/alfio.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/alfio ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN}	${WRKSRC}/alfio.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
