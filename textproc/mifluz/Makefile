PORTNAME=	mifluz
PORTVERSION=	0.26.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to build and query a full text inverted index
WWW=		https://www.gnu.org/software/mifluz/

LICENSE=	GPLv3

USES=		bison compiler iconv libtool localbase:ldflags pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-posixmutexes \
		--localstatedir="${PREFIX}/var" \
		--without-unac

INSTALL_TARGET=	install-strip

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

CONFLICTS_INSTALL=	htdig # bin/htdb_dump bin/htdb_load bin/htdb_stat

SUB_FILES=	pkg-message

INFO=		mifluz

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#ifndef HAVE_ALLOCA/s|_H||' ${WRKSRC}/clib/strncoll2.c

.include <bsd.port.mk>
