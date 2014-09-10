# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	getdp
PORTVERSION=	2.2.1
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://www.geuz.org/getdp/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Rather general finite element solver using mixed finite elements

LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl	\
		liblapack.so:${PORTSDIR}/math/lapack

USES=		fortran gmake tar:tgz
GNU_CONFIGURE=	yes
# Using --enable-sparskit instead of math/petsc.  The maintainer couldn't get
# the math/petsc to work.  This is a bmake/gmake clash.
CONFIGURE_ARGS=	--with-gsl-prefix=${LOCALBASE}	\
		--with-blas-lapack-prefix=${LOCALBASE} \
		--enable-sparskit
MAKE_ARGS=	bindir=${STAGEDIR}${PREFIX}/bin mandir=${STAGEDIR}${PREFIX}/man
WANT_PERL=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's/-lgfortran/& $${LDFLAGS}/' ${WRKSRC}/configure

post-install:
	cd ${WRKSRC}/doc && ${FIND} -s ${WRKSRC}/doc/* | ${SED} -e 's#${WRKSRC}/doc/##' | ${CPIO} -pmud -R ${BINOWN}:${BINGRP} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/demos && ${FIND} -s ${WRKSRC}/demos/* | ${SED} -e 's#${WRKSRC}/demos/##' | ${CPIO} -pmud -R ${BINOWN}:${BINGRP} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if defined(MAINTAINER_MODE)
regression-test:	install
	cd ${WRKSRC}/demos && yes "" | ${PORTNAME} magnet.pro -solve MagSta_phi
.endif

.include <bsd.port.post.mk>
