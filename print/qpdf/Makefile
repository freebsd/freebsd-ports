PORTNAME=	qpdf
DISTVERSION=	11.2.0
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Command-line tools for transforming and inspecting PDF documents
WWW=		http://qpdf.sourceforge.net

LICENSE=	ART20 APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_ART20=	${WRKSRC}/Artistic-2.0
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang cmake cpe jpeg libtool localbase
USE_LDCONFIG=	yes
CPE_VENDOR=	qpdf_project

CMAKE_ARGS=	-DHAVE_EXTERN_LONG_TIMEZONE=0 \
		-DBUILD_STATIC_LIBS=0 \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
