PORTNAME=	wordnet
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	SF/pywordnet/pywordnet/${PORTVERSION}:pywn \
		http://wordnetcode.princeton.edu/${WN_VERSION}/:wn \
		ftp://ftp.ims.uni-stuttgart.de/pub/WordNet/${WN_VERSION}/:wn
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pywordnet-${PORTVERSION}.tar.gz:pywn \
		WordNet-${WN_VERSION}.tar.gz:wn

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Interface to WordNet

USES=		dos2unix python:3.6+
USE_PYTHON=	distutils autoplist

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
# concordance.py uses CR line terminators which cannot be fixed by USES=dos2unix
	@${CP} ${FILESDIR}/concordance.py ${WRKSRC}/concordance.py
	@${SED} -e 's|/usr/local/wordnet2.0|${PREFIX}/${WORDNETDATA}|g' \
		-e 's|os.path.join(WNHOME.*))|WNHOME)|g' ${WRKSRC}/wordnet.py \
		> ${WRKSRC}/wordnet.py.tmp && ${CAT} ${WRKSRC}/wordnet.py.tmp \
		> ${WRKSRC}/wordnet.py

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${WORDNETDATA}
.for f in ${WN_DICTFILES}
	${INSTALL_DATA} ${WN_WRKSRC}/dict/${f} ${STAGEDIR}${PREFIX}/${WORDNETDATA}/
.endfor

.include <bsd.port.mk>
