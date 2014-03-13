# $FreeBSD$

PORTNAME=	symports
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://isis.poly.edu/~eitan/files/
DISTNAME=	auto-symlink-virtual-${PORTVERSION}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Automatically generate symlinks for virtual categories

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/symports.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/auto-symlink-virtual.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/symports.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/symports.1

.include <bsd.port.mk>
