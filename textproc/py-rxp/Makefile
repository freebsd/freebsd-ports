# Ports collection makefile for:	py-rxp
# Date created:		10 May 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	rxp
PORTVERSION=	0.7
CATEGORIES=	textproc python
MASTER_SITES=	http://www.reportlab.com/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyRXP-${PORTVERSION:S/./-/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-rxp
DOCSDIR=	${PREFIX}/share/doc/py-rxp

post-patch:
	@${PERL} -pi -e 's/freebsd4/freebsd4","freebsd5/g' ${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
