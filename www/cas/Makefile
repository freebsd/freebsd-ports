PORTNAME=	cas
PORTVERSION=	3.8.0
CATEGORIES=	www devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	C++ Application Server
WWW=		https://github.com/CommunicoPublic/cas

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libctpp2.so:textproc/ctpp2 \
		libexpat.so:textproc/expat2 \
		libpcre.so:devel/pcre

USES=		cmake:insource iconv ssl
USE_GITHUB=	yes
GH_ACCOUNT=	CommunicoPublic
GH_TAGNAME=	4fbf8e3
USE_LDCONFIG=	yes

.if !defined(WITH_DEBUG)
CMAKE_OFF+=	DEBUG_MODE
.endif

OPTIONS_DEFINE=	APACHE EXAMPLES XMLRPC
OPTIONS_DEFAULT=	APACHE XMLRPC
OPTIONS_SUB=	yes

APACHE_USES=		apache
APACHE_CMAKE_OFF=	-DBUILD_APACHE2X_MODULE:BOOL=OFF

EXAMPLES_CMAKE_OFF=	-DINSTALL_EXAMPLE_MODULES:BOOL=OFF

XMLRPC_DESC=		Build cURL-based XMLRPC client
XMLRPC_LIB_DEPENDS=	libcurl.so:ftp/curl
XMLRPC_CMAKE_OFF=	-DBUILD_CURL_XMLRPC_CLIENT:BOOL=OFF

post-patch:
	@${REINPLACE_CMD} -e 's,real_pcre,&8_or_16,' \
		${WRKSRC}/include/ASPCRE.hpp
	@${REINPLACE_CMD} -e 's,while (szString,while (*szString,' \
		${WRKSRC}/src/SAPI/util/ASSAPIUtil.cpp

.include <bsd.port.mk>
