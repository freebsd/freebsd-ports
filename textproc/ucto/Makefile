# $FreeBSD$

PORTNAME=	ucto
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced rule-based (regular-expression) and unicode-aware tokenizer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>0:devel/autoconf-archive \
		uctodata>0:textproc/uctodata
LIB_DEPENDS=	libexttextcat-2.0.so:textproc/libexttextcat \
		libfolia.so:textproc/libfolia \
		libicuio.so:devel/icu \
		libomp.so:devel/openmp \
		libticcutils.so:devel/ticcutils
RUN_DEPENDS=	uctodata>0:textproc/uctodata

USES=		autoreconf gmake gnome libedit libtool pkgconfig readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	LanguageMachines
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
