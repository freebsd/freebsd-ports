# New ports collection makefile for:	py-freetype
# Date created:				3 February 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-freetype
PORTVERSION=	0.5
CATEGORIES=	print python
MASTER_SITES=	http://starship.python.net/crew/kernr/source/
DISTNAME=	PyFT-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_ZIP=	yes
USE_PYTHON=	yes

pre-configure:
	${LN} -sf ${LOCALBASE}/lib/${PYTHON_VERSION}/config/Makefile.pre.in ${WRKSRC}/
	${LN} -sf ${WRKSRC}/Setup.w32 ${WRKSRC}/Setup.in

do-configure:
	cd ${WRKSRC} && ${MAKE} -f Makefile.pre.in boot

post-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

post-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} *.py *.pyc *.pyo \
		${PREFIX}/lib/${PYTHON_VERSION}/site-packages

.include <bsd.port.mk>
