# New ports collection Makefile for:		ClibPDF
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	clibpdf
PORTVERSION=	2.02.r1
CATEGORIES=	print
MASTER_SITES=	http://www.fastio.com/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A library for creating PDF (Acrobat) files directly via C language programs

WRKSRC=		${WRKDIR}/ClibPDF/source

INSTALLS_SHLIB=	yes
SHLIB_VER=	0

MAKEFILE=	Makefile.FreeBSD
ALL_TARGET=	lib shlib

PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

NO_CDROM=	"Needs a license to bundle with other products"

do-install:
	${INSTALL_DATA} ${WRKSRC}/cpdflib.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libcpdf.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libcpdf.so ${PREFIX}/lib/libcpdf.so.${SHLIB_VER}
	${LN} -sf libcpdf.so.${SHLIB_VER} ${PREFIX}/lib/libcpdf.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/clibpdf
	${CP} -R ${WRKSRC}/../examples/ ${PREFIX}/share/examples/clibpdf/
	${MKDIR} ${PREFIX}/share/doc/clibpdf
	${CP} -R ${WRKSRC}/../doc/ ${PREFIX}/share/doc/clibpdf/
	${INSTALL_DATA} ${WRKSRC}/../*.pdf ${PREFIX}/share/doc/clibpdf/
.endif

.include <bsd.port.mk>
