# Created by: Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
# $FreeBSD$

PORTNAME=	pari
PORTVERSION=	2.3.5
PORTEPOCH=	2
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/OLD/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mathematics library and advanced calculator package

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:math/gmp

MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	gp
CONFIGURE_ENV=	ld="${LD}" perl="${PERL}" ranlib="${RANLIB}"
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man/man1 \
		--prefix=${PREFIX} \
		--share-prefix=${PREFIX}/share \
		--with-gmp=${LOCALBASE}
HAS_CONFIGURE=	yes
MAKE_ENV+=	STRIP="${STRIP_CMD}"
USE_LDCONFIG=	yes
USE_PERL5=	build
USES=		perl5

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS X11
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS X11
.ifndef WITH_DEBUG
OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fno-strict-aliasing -fomit-frame-pointer
.endif
X11_CONFIGURE_ON=	--graphic=X11
X11_CONFIGURE_OFF=	--graphic=none
X11_USE=		xorg=x11

PLIST_SUB=	GP_VERSION=${GP_VERSION} PORTVERSION=${PORTVERSION}
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

GP_VERSION=	${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -E '/^list=/s/(ld|ranlib|perl|emacs)//g' \
		${WRKSRC}/Configure
	@${REINPLACE_CMD} -e '/^CFLAGS=/s/\$$cflags//' \
		${WRKSRC}/config/get_cc

post-build:
	@${STRIP_CMD} ${WRKSRC}/*/libpari-gmp.so.*

.include <bsd.port.mk>
