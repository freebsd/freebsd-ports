PORTNAME=	libcdio
DISTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library
WWW=		https://www.gnu.org/software/libcdio/

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
		--disable-vcd-info \
		${ICONV_CONFIGURE_ARG}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

LIBS+=		${ICONV_LIB}

INFO=		libcdio

.include <bsd.port.mk>
