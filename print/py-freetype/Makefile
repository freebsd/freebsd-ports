# New ports collection makefile for:	py-freetype
# Date created:				3 February 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-freetype
PORTVERSION=	0.65
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	http://starship.python.net/crew/kernr/source/
DISTNAME=	PyFT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python wrapping of the FreeType 1.2 fonts rendering engine

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_FREETYPE=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 220
MAKEFILE_PREIN=	${FILESDIR}/Makefile.pre.in
.else
MAKEFILE_PREIN=	${LOCALBASE}/lib/${PYTHON_VERSION}/config/Makefile.pre.in
.endif

pre-configure:
.if ${PYTHON_REL} >= 230
	${SED} -e 's,@DEFS@,,g' ${MAKEFILE_PREIN} > ${WRKSRC}/Makefile.pre.in
.else
	${LN} -sf ${MAKEFILE_PREIN} ${WRKSRC}/
.endif
	${LN} -sf ${WRKSRC}/Setup.w32 ${WRKSRC}/Setup.in
	${RM} -f ${WRKSRC}/Setup

do-configure:
	cd ${WRKSRC} && ${MAKE} -f Makefile.pre.in boot

post-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

post-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} *.py *.pyc *.pyo \
		${PREFIX}/lib/${PYTHON_VERSION}/site-packages

.include <bsd.port.post.mk>
