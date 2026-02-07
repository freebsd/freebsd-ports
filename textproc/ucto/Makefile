PORTNAME=	ucto
DISTVERSION=	0.35
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/LanguageMachines/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced rule-based (regular-expression) and unicode-aware tokenizer
WWW=		https://languagemachines.github.io/ucto/ \
		https://github.com/LanguageMachines/ucto

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	uctodata>0:textproc/uctodata
LIB_DEPENDS=	libexttextcat-2.0.so:textproc/libexttextcat \
		libfolia.so:textproc/libfolia \
		libicuio.so:devel/icu \
		libticcutils.so:devel/ticcutils
RUN_DEPENDS=	uctodata>0:textproc/uctodata

USES=		compiler:c++11-lang gmake gnome libedit libtool \
		pathfix pkgconfig readline
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

TEST_TARGET=	check
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-static

post-patch:
	@${REINPLACE_CMD} -e 's|-g -O3||g' \
		${PATCH_WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
