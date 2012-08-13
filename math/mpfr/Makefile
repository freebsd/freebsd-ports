# New ports collection makefile for:	mpfr
# Date created:			28 Aug 2005
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpfr
PORTVERSION=	3.1.1
CATEGORIES=	math devel
MASTER_SITES=	http://www.mpfr.org/mpfr-current/
DIST_SUBDIR=	${DISTNAME}

PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A library for multiple-precision floating-point computations

LICENSE=	LGPL3

#PATCH_DEPENDS=	gpatch:${PORTSDIR}/devel/patch
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

#PATCHLEVEL=	10
#PATCHFILES!=	/usr/bin/jot -s " " -w patch%02d ${PATCHLEVEL} 1 ${PATCHLEVEL}
#PATCH=		${LOCALBASE}/bin/gpatch

USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack

USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}

USE_LDCONFIG=	yes

INFO=		mpfr

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 803000
CONFIGURE_ARGS+=	--disable-thread-safe
.endif

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} 's/install-nobase_dist_docDATA$$//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's/install-data-am: install-dist_docDATA/install-data-am:/' \
		${WRKSRC}/doc/Makefile.in
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
