PORTNAME=	libfolia
DISTVERSION=	2.15
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/LanguageMachines/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for FoLiA, a format for annotated language resources
WWW=		https://proycon.github.io/folia/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libticcutils.so:devel/ticcutils

USES=		compiler:c++14-lang gmake gnome libtool pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|-g -O3||g' \
		${PATCH_WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
