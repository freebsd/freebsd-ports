# ex:ts=8
# Ports collection Makefile for:	roap
# Date created:			Apr 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	roap
PORTVERSION=	0.1.2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Region Oriented Ascii Processor

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCS=	README README.ja USAGE USAGE.ja

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roap ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${CP} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
