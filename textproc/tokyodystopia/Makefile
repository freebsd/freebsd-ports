# New ports collection makefile for:	tokyodystopia
# Date created:		2009-02-04
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tokyodystopia
PORTVERSION=	0.9.14
CATEGORIES=	textproc
MASTER_SITES=	http://1978th.net/tokyodystopia/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A full-text search system based on Tokyo Cabinet

LIB_DEPENDS=	tokyocabinet:${PORTSDIR}/databases/tokyocabinet

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include

MAN1=	dystmgr.1 \
	dysttest.1 \
	lapumgr.1 \
	laputest.1 \
	tcqmgr.1 \
	tcqtest.1 \
	tcwmgr.1 \
	tcwtest.1
MAN3=	dystopia.3 \
	laputa.3 \
	tcidb.3 \
	tcjdb.3 \
	tcqdb.3 \
	tcwdb.3

SHLIB_VER=	1.15.0
SHLIB_VER_MAJ=	1

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

post-patch:
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|DATADIR =.*|DATADIR = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|mkdir -p $$(DESTDIR)$$(DATADIR)||' \
		-e 's|cp -Rf $$(DOCUMENTFILES) $$(DESTDIR)$$(DATADIR)||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
