PORTNAME=	libcoap
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.0
CATEGORIES=	net

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	C implementation of the Constrained Application Protocol

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc \
		gsed:textproc/gsed
LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	obgm

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	sed=gsed
PORTSCOUT=	limit:^4\.

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_DEFAULT=	DOXYGEN

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	doxygen

.include <bsd.port.mk>
