# Ports collection makefile for:	py-rxp
# Date created:		10 May 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	rxp
PORTVERSION=	0.9
CATEGORIES=	textproc python
MASTER_SITES=	http://www.reportlab.com/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyRXP-${PORTVERSION:S/./-/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Fast validating XML parser for Python

NO_WRKSUBDIR=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-rxp
DOCSDIR=	${PREFIX}/share/doc/py-rxp

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
BROKEN=		"Does not build on FreeBSD >= 6.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/freebsd4/freebsd4","freebsd5/g' ${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
