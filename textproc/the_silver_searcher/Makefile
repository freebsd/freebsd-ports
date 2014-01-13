# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	the_silver_searcher
PORTVERSION=	0.17
CATEGORIES=	textproc
#MASTER_SITES=	http://geoff.greer.fm/ag/releases/

MAINTAINER=	gslin@gslin.org
COMMENT=	A code-searching tool similar to ack but faster

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	ggreer
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	b0afccd

ACLOCAL_ARGS+=	-I ${ACLOCAL_DIR}
AUTOMAKE_ARGS+=	--add-missing
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LZMA_LIBS=-llzma
CONFIGURE_ARGS+=	LZMA_CFLAGS=-I/usr/include
USE_AUTOTOOLS=	aclocal autoconf autoheader automake
USES=		pkgconfig

.include <bsd.port.mk>
