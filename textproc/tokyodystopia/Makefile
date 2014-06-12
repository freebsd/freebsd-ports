# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tokyodystopia
PORTVERSION=	0.9.15
CATEGORIES=	textproc
MASTER_SITES=	http://fallabs.com/${PORTNAME}/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A full-text search system based on Tokyo Cabinet

LICENSE=	LGPL

LIB_DEPENDS=	libtokyocabinet.so:${PORTSDIR}/databases/tokyocabinet

GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include

SHLIB_VER=	1.15.0
SHLIB_VER_MAJ=	1

PLIST_SUB=	SHLIB_VER=${SHLIB_VER} SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

.include <bsd.port.options.mk>

post-extract:
	@${RM} ${WRKSRC}/doc/index.html~

post-patch:
	@${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		-e 's|DATADIR =.*|DATADIR = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.if defined(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's|mkdir -p $$(DESTDIR)$$(DATADIR)||' \
		-e 's|cp -Rf $$(DOCUMENTFILES) $$(DESTDIR)$$(DATADIR)||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
