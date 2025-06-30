PORTNAME=	libfolia
DISTVERSION=	2.21
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/LanguageMachines/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for FoLiA, a format for annotated language resources
WWW=		https://proycon.github.io/folia/ \
		https://github.com/proycon/folia

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libticcutils.so:devel/ticcutils

USES=		autoreconf compiler:c++17-lang gmake gnome libtool \
		pathfix pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
