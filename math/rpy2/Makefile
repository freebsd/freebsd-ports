# Created by: ijliao
# $FreeBSD$

PORTNAME=	rpy2
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	CHEESESHOP

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to the R Programming Language

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY} \
		R:${PORTSDIR}/math/R
RUN_DEPENDS=	${PYNUMPY} \
		R:${PORTSDIR}/math/R

USES=		python readline
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

pre-configure:
	@(if [ ! -e ${LOCALBASE}/lib/R/lib/libR.so ] ; then \
	${ECHO_MSG} "==> ${PKGNAME} requires math/R to be built WITH_LIBR" ; \
	exit 1; fi)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rpy2/rinterface/*.so

.include <bsd.port.mk>
