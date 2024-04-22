PORTNAME=	libcoap
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.4
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	C implementation of the Constrained Application Protocol
WWW=		https://github.com/obgm/libcoap

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc \
		gsed:textproc/gsed
LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	obgm

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

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

CONFIGURE_ENV=ac_cv_path_SED=${LOCALBASE}/bin/gsed
.include <bsd.port.mk>
