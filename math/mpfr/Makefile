PORTNAME=	mpfr
DISTVERSION=	4.2.1
PORTEPOCH=	1
CATEGORIES=	math devel
MASTER_SITES=	GNU \
		https://www.mpfr.org/mpfr-${DISTVERSION}/
DIST_SUBDIR=	${DISTNAME}

PATCH_SITES=	https://www.mpfr.org/mpfr-${DISTVERSION}/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Library for multiple-precision floating-point computations
WWW=		https://www.mpfr.org/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake libtool pathfix tar:xz

#PATCHLEVEL=	12
#PATCHFILES!=	/usr/bin/jot -s " " -w patch%02d ${PATCHLEVEL} 1 ${PATCHLEVEL}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS INFO
OPTIONS_DEFAULT=	INFO

INFO_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-no-info
INFO_USES=		makeinfo
INFO_INFO=		mpfr

.include <bsd.port.mk>
