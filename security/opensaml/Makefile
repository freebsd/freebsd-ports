# Created by: Janos Mohacsi
# $FreeBSD$

PORTNAME=	opensaml
PORTVERSION=	3.0.1
CATEGORIES=	security
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/${PORTVERSION}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Open source implementation of SAML2

LICENSE=	APACHE20

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libcurl.so:ftp/curl \
		liblog4shib.so:devel/log4shib \
		libxml-security-c.so:security/apache-xml-security-c \
		libxerces-c.so:textproc/xerces-c3 \
		libxmltooling.so:devel/xmltooling

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-doxygen-doc --disable-dependency-tracking
USES=		gmake libtool pkgconfig tar:bzip2 ssl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgdocdir.*=.*,pkgdocdir = ${DOCSDIR},' \
		${WRKSRC}/doc/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,doc ,,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
