PORTNAME=	libcdio
DISTVERSION=	2.3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library
WWW=		https://github.com/libcdio/libcdio/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	genisoimage:sysutils/genisoimage

USES=		compiler:c11 cpe gmake iconv libtool localbase \
		ncurses pathfix perl5 pkgconfig tar:bzip2
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cddb \
		--disable-static \
		--disable-vcd-info \
		${ICONV_CONFIGURE_ARG}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

LIBS+=		${ICONV_LIB}

INFO=		libcdio

.include <bsd.port.mk>
