# New ports collection makefile for:	py-wordnet
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	wordnet
PORTVERSION=	2.0.1
PORTREVISION=	0
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pywordnet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pywordnet-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python Interface to WordNet

RUN_DEPENDS=	${WORDNETBASE}/lexnames:${PORTSDIR}/textproc/wordnet

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WORDNETBASE?=	${LOCALBASE}/share/WordNet-${WORDNET_VERSION}
WORDNET_VERSION?=	2.0

post-patch:
	@${SED} -e 's|/usr/local/wordnet${WORDNET_VERSION}|${WORDNETBASE}|g' \
		-e 's|os.path.join(WNHOME.*))|WNHOME)|g' ${WRKSRC}/wordnet.py \
		> ${WRKSRC}/wordnet.py.tmp && ${CAT} ${WRKSRC}/wordnet.py.tmp \
		> ${WRKSRC}/wordnet.py

.include <bsd.port.mk>
