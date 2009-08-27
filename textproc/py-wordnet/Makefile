# New ports collection makefile for:	py-wordnet
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	wordnet
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	SF/pywordnet/pywordnet/${PORTVERSION}:pywn \
		ftp://ftp.cogsci.princeton.edu/pub/wordnet/${WN_VERSION}/:wn \
		http://www.cogsci.princeton.edu/${WN_VERSION}/:wn \
		ftp://ftp.ims.uni-stuttgart.de/pub/WordNet/${WN_VERSION}/:wn
MASTER_SITE_SUBDIR=	pywordnet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pywordnet-${PORTVERSION}.tar.gz:pywn \
		WordNet-${WN_VERSION}.tar.gz:wn

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python Interface to WordNet

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pywordnet
WRKSRC=		${WRKDIR}/py${PORTNAME}-${PORTVERSION}
PLIST_SUB=	WNDATA=${WORDNETDATA}

WN_WRKSRC=	${WRKDIR}/WordNet-${WN_VERSION}
WN_VERSION=	2.0
WORDNETDATA=	share/py-${PORTNAME}
WN_DICTFILES=	adj.exc adv.exc cntlist cntlist.rev data.adj data.adv \
		data.noun data.verb frames.vrb index.adj index.adv index.noun \
		index.sense index.verb lexnames noun.exc sentidx.vrb sents.vrb\
		verb.exc

post-patch:
	@${SED} -e 's|/usr/local/wordnet2.0|${PREFIX}/${WORDNETDATA}|g' \
		-e 's|os.path.join(WNHOME.*))|WNHOME)|g' ${WRKSRC}/wordnet.py \
		> ${WRKSRC}/wordnet.py.tmp && ${CAT} ${WRKSRC}/wordnet.py.tmp \
		> ${WRKSRC}/wordnet.py

post-install:
	${MKDIR} ${PREFIX}/${WORDNETDATA}
.for f in ${WN_DICTFILES}
	${INSTALL_DATA} ${WN_WRKSRC}/dict/${f} ${PREFIX}/${WORDNETDATA}/
.endfor

.include <bsd.port.mk>
