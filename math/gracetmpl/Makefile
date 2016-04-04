# Created by: ijliao
# $FreeBSD$

PORTNAME=	gracetmpl
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	math print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an easy way to use existing grace-files as a template

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:math/py-numarray
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:math/py-numarray

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake python tar:bzip2
MAKE_ARGS=	PREFIX="${PREFIX}" \
		BIN_PREFIX="${PREFIX}/bin" \
		LIB_PREFIX="${PREFIX}/lib" \
		INC_PREFIX="${PREFIX}/include" \
		DOC_PREFIX="${DOCSDIR}" \
		AR="${AR}" \
		CPP="${CXX} ${LDFLAGS}" \
		CPPFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CXX="${CXX}" \
		PYTHON="${PYTHON_CMD}"
ALL_TARGET=	all pythonwrap
INSTALL_TARGET=	install
USE_GCC=	yes

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

post-extract:
	@${ECHO_CMD} -n > ${WRKSRC}/Makefile.defs

post-patch:
	@${REINPLACE_CMD} -e 's|/gracetmpl\.a|/libgracetmpl.a|g' ${WRKSRC}/gracetmpl-config.in

post-install:
	@(cd ${INSTALL_WRKSRC}/python; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py \
		install --root=${STAGEDIR} --prefix=${PREFIX} -c -O1)
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/graceTMPL/graceTMPL.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
