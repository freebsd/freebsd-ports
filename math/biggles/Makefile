# Created by: ijliao
# $FreeBSD$

PORTNAME=	biggles
PORTVERSION=	1.6.6
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	SF
DISTNAME=	python2-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create publication-quality 2D scientific plots

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libplot.so:graphics/plotutils

USES=		gmake python:2.7
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS} -fPIC" \
		LIBPLOT_CPPFLAGS="-I${LOCALBASE}/include" \
		LIBPLOT_LDFLAGS="-L${LOCALBASE}/lib -lplot" \
		PYTHON="${PYTHON_CMD}"

post-patch:
	@${REINPLACE_CMD} -e '/CC/s,gcc,$$\{CC\},' ${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's|= python|= ${PYTHON_CMD}|' ${WRKSRC}/make.inc

pre-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/biggles/libplot
	(cd ${WRKSRC}/src && ${INSTALL_DATA} *.ini *.py *.pyc *.pyo \
		${STAGEDIR}${PYTHON_SITELIBDIR}/biggles)
	(cd ${WRKSRC}/src && ${INSTALL_LIB} *.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/biggles)
	(cd ${WRKSRC}/src/libplot/ && ${INSTALL_DATA} *.py *.pyc *.pyo \
		${STAGEDIR}${PYTHON_SITELIBDIR}/biggles/libplot)
	(cd ${WRKSRC}/src/libplot/ && ${INSTALL_LIB} *.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/biggles/libplot)

.include <bsd.port.mk>
