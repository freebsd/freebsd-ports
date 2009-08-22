# ex:ts=8
# Ports collection makefile for:	GraceTMPL
# Date created:			Oct 28, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gracetmpl
PORTVERSION=	0.3.2
CATEGORIES=	math print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an easy way to use existing grace-files as a template

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		BIN_PREFIX="${PREFIX}/bin" \
		LIB_PREFIX="${PREFIX}/lib" \
		INC_PREFIX="${PREFIX}/include" \
		DOC_PREFIX="${DOCSDIR}" \
		AR="${AR}" \
		CPP="${CXX} ${LDFLAGS}" \
		CPPFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CXX="${CXX}"
ALL_TARGET=	all pythonwrap
INSTALL_TARGET=	install pythonwrap_install

INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGNAME=	graceTMPL
PYDISTUTILS_EGGINFODIR=	${PYTHON_SITELIBDIR}/graceTMPL

post-extract:
	@${ECHO_CMD} -n > ${WRKSRC}/Makefile.defs

post-patch:
	@${REINPLACE_CMD} -e 's|/gracetmpl\.a|/libgracetmpl.a|g' ${WRKSRC}/gracetmpl-config.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
