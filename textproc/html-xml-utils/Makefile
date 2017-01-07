# Created by: Takefu <takefu@airport.fm>
# $FreeBSD$

PORTNAME=	html-xml-utils
PORTVERSION=	7.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/Tools/HTML-XML-utils/

MAINTAINER=	takefu@airport.fm
COMMENT=	Utilities for manipulating HTML and XML files

LICENSE=	W3C
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	W3C Software Notice and License (2002-12-31)
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake iconv localbase shebangfix
GNU_CONFIGURE=	yes

SHEBANG_FILES=	${WRKSRC}/hxcite-mkbib
CONFIGURE_ARGS=	LDFLAGS=${ICONV_LIB}

.include <bsd.port.mk>
