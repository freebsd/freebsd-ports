# New ports collection makefile for:	numpy
# Date created:				24 July 2006
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	numpy
PORTVERSION=	1.0r1
CATEGORIES=	math python
MASTER_SITES=	http://numpy.scipy.org/:doc \
		${MASTER_SITE_SOURCEFORGE:S/$/:source/}
MASTER_SITE_SUBDIR=	numpy/:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	numpy-${PORTVERSION:S/r/rc/}${EXTRACT_SUFX}:source \
		numpy.pdf:doc
EXTRACT_ONLY=	numpy-${PORTVERSION:S/r/rc/}${EXTRACT_SUFX}

MAINTAINER=	db@db.net
COMMENT=	The New Numeric Extension to Python

CONFLICTS=	f2py-*

OPTIONS=	ATLAS "Use optimized blas library" Off

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
MAN1=		f2py.1

LATEST_LINK=	py-${PORTNAME}
WRKSRC=	${WRKDIR}/${DISTNAME:S/r/rc/}

.include <bsd.port.pre.mk>

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.1:${PORTSDIR}/math/atlas
.else
LIB_DEPENDS+=	lapack.3:${PORTSDIR}/math/lapack \
		blas.1:${PORTSDIR}/math/blas
.endif

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

pre-fetch:
.if ${PYTHON_REL} < 200
	@${ECHO} "Py-numpy doesn't work with Python versions < 2.0."
	@${ECHO} "Please use the py-numeric17 port for these."
	@${FALSE}
.endif

post-extract:
	@${CP} ${DISTDIR}/numpy.pdf ${WRKDIR}

post-patch:
.if defined(WITH_ATLAS)
	@${CP} ${FILESDIR}/site.cfg ${WRKSRC}
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/numpy/f2py/f2py.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/numpy.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
