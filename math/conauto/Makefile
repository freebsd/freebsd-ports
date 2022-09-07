PORTNAME=	conauto
DISTVERSION=	2.03
CATEGORIES=	math
MASTER_SITES=	https://sites.google.com/site/giconauto/home/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for graph isomorphism testing & automorphism group computation
WWW=		https://sites.google.com/site/giconauto/

LICENSE=	GPLv3+

USES=		gmake

WRKSRC_SUBDIR=	src

MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}"

CFLAGS+=	-fcommon

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${PORTNAME}* ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
