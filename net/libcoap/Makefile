# $FreeBSD$

PORTNAME=	libcoap
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.1
CATEGORIES=	net

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	C implementation of the Constrained Application Protocol

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	obgm

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_DEFAULT=	DOXYGEN
PORTDOCS=	*

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	doxygen

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
