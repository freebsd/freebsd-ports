PORTNAME=	the_silver_searcher
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	textproc
PATCH_SITES=	https://gitee.com/src-openeuler/${PORTNAME}/raw/97978596560d1321a171ec2778aa0f894d194939/:pcre2
PATCHFILES=	Add-support-for-libpcre2.patch:-p1:pcre2

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Code-searching tool similar to ack but faster
WWW=		https://github.com/ggreer/the_silver_searcher

LICENSE=	APACHE20

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
TEST_DEPENDS=	cram:devel/cram

USES=		autoreconf pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ggreer

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-pcre2 \
		LZMA_CFLAGS=-I/usr/include \
		LZMA_LIBS=-llzma
TEST_TARGET=	test
LDFLAGS+=	-L/usr/lib -llzma

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${MV} ${STAGEDIR}${DATADIR}/completions/ag.bashcomp.sh \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${RMDIR} ${STAGEDIR}${DATADIR}/completions
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
