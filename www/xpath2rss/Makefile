# ex:ts=8
# Ports collection makefile for:	xpath2rss
# Date created:			Jun 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xpath2rss
PORTVERSION=	0.7
CATEGORIES=	www python
MASTER_SITES=	http://www.mnot.net/xpath2rss/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML to RSS converter

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	${PYXML}

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	(cd ${WRKSRC} ; ${INSTALL_SCRIPT} *.py ${PYTHON_SITELIBDIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
