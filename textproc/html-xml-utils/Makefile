# Created by: Takefu <takefu@airport.fm>
# $FreeBSD$

PORTNAME=	html-xml-utils
PORTVERSION=	7.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/Tools/HTML-XML-utils/

MAINTAINER=	takefu@airport.fm
COMMENT=	Utilities for manipulating HTML and XML files

LICENSE=	W3C
LICENSE_NAME=	W3C Software Notice and License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept

USES=		gmake iconv shebangfix
GNU_CONFIGURE=	yes

SHEBANG_FILES=	${WRKSRC}/hxcite-mkbib

CONFIGURE_ARGS=	CPPFLAGS=-I${LOCALBASE}/include\
		LDFLAGS="-L${LOCALBASE}/lib ${ICONV_LIB}"

.include <bsd.port.mk>
