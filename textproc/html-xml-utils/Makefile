PORTNAME=	html-xml-utils
PORTVERSION=	8.0
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

SHEBANG_FILES=	${WRKSRC}/hxcite-mkbib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS=${ICONV_LIB}

OPTIONS_DEFINE=		CURL IDN IDN2 DOCS
OPTIONS_SUB=		yes
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl=${LOCALBASE}
IDN_LIB_DEPENDS=	libidn.so:dns/libidn
IDN_CONFIGURE_WITH=	libidn=${LOCALBASE}
IDN2_DESC=		Use dns/libidn2 (IDNA2008 library)
IDN2_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN2_CONFIGURE_WITH=	libidn2=${LOCALBASE}

.include <bsd.port.mk>
