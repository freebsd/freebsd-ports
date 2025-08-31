PORTNAME=	bibata-cursor-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.7
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/ful1e5/Bibata_Cursor/releases/download/${DISTVERSIONFULL}/
DISTNAME=	Bibata
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Open source, compact, and material designed cursor set
WWW=		https://github.com/ful1e5/Bibata_Cursor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

do-install:
	cd ${WRKSRC} && \
	${COPYTREE_SHARE} "Bibata-*" ${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>
