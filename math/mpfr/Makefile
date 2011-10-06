# New ports collection makefile for:	mpfr
# Date created:			28 Aug 2005
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpfr
PORTVERSION=	3.1.0
CATEGORIES=	math devel
MASTER_SITES=	http://www.mpfr.org/mpfr-current/
DIST_SUBDIR=	mpfr

PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A library for multiple-precision floating-point computations

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

#PATCHLEVEL=	1
#PATCHFILES!=	/usr/bin/jot -s " " -w patch%02d ${PATCHLEVEL} 1 ${PATCHLEVEL}

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack

USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} \
		--disable-thread-safe
USE_LDCONFIG=	yes

INFO=		mpfr

PORTDOCS=	*

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} 's/install-nobase_dist_docDATA$$//' \
		${WRKSRC}/Makefile.in
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
