PORTNAME=	libcdio
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library
WWW=		https://www.gnu.org/software/libcdio/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcddb.so:audio/libcddb
TEST_DEPENDS=	genisoimage:sysutils/genisoimage

USES=		compiler:c11 cpe gmake iconv libtool localbase \
		ncurses pathfix perl5 pkgconfig tar:bzip2
USE_PERL5=	build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
LIBS+=		${ICONV_LIB}

INFO=		libcdio
CPE_VENDOR=	gnu
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
