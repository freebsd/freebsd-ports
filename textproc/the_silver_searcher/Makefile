# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	the_silver_searcher
PORTVERSION=	2.1.0
CATEGORIES=	textproc

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Code-searching tool similar to ack but faster

LICENSE=	APACHE20

LIB_DEPENDS=	libpcre.so:devel/pcre
TEST_DEPENDS=	cram:devel/cram

USE_GITHUB=	yes
GH_ACCOUNT=	ggreer

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LZMA_LIBS=-llzma
CONFIGURE_ARGS+=LZMA_CFLAGS=-I/usr/include
LDFLAGS+=	-L/usr/lib -llzma
USES=		autoreconf pkgconfig
TEST_TARGET=	test

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${MV} ${STAGEDIR}${DATADIR}/completions/ag.bashcomp.sh \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${RMDIR} ${STAGEDIR}${DATADIR}/completions
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
