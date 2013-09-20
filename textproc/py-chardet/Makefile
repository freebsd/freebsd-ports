# Created by: arved
# $FreeBSD$

PORTNAME=	chardet
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	textproc python
#MASTER_SITES=	http://chardet.feedparser.org/download/
MASTER_SITES=	http://darkstar.ist.utl.pt/slackware/addon/slacky/%SUBDIR%/ \
		http://repository.slacky.eu/%SUBDIR%/ \
		http://slack.isper.sk/pub/%SUBDIR%/ \
		http://www.slackware.org.uk/slacky/%SUBDIR%/
MASTER_SITE_SUBDIR=	slackware64-13.37/libraries/python2-${PORTNAME}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python2-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Character encoding auto-detection in Python

LICENSE=	LGPL21

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	*

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
