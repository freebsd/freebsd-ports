# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tokyodystopia
PORTVERSION=	0.9.15
CATEGORIES=	textproc
MASTER_SITES=	https://dbmx.net/${PORTNAME}/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Full-text search system based on Tokyo Cabinet

LICENSE=	LGPL21

LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

GNU_CONFIGURE=	yes
USES=		gmake pathfix
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include

SHLIB_VER=	1.15.0
SHLIB_VER_MAJ=	1

PLIST_SUB=	SHLIB_VER=${SHLIB_VER} SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/doc/index.html~

post-patch:
	@${REINPLACE_CMD} -e 's|DATADIR =.*|DATADIR = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
