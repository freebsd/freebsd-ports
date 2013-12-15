# Created by: ijliao
# $FreeBSD$

PORTNAME=	biggles
PORTVERSION=	1.6.6
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF
DISTNAME=	python2-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create publication-quality 2D scientific plots

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libplot.so:${PORTSDIR}/graphics/plotutils

USES=		gmake
USE_PYTHON=	2
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS} -fPIC" \
		LIBPLOT_CPPFLAGS="-I${LOCALBASE}/include" \
		LIBPLOT_LDFLAGS="-L${LOCALBASE}/lib -lplot" \
		PYTHON="${PYTHON_CMD}"

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/CC/s,gcc,$$\{CC\},' ${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's|= python|= ${PYTHON_CMD}|' ${WRKSRC}/make.inc

pre-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/biggles
.for ext in ini so py pyc pyo
	${INSTALL_DATA} ${WRKSRC}/src/*.${ext} ${PYTHON_SITELIBDIR}/biggles
.endfor
	@${MKDIR} ${PYTHON_SITELIBDIR}/biggles/libplot
.for ext in so py pyc pyo
	${INSTALL_DATA} ${WRKSRC}/src/libplot/*.${ext} ${PYTHON_SITELIBDIR}/biggles/libplot
.endfor

.include <bsd.port.mk>
