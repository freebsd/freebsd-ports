# New ports collection makefile for:	py-wordnet
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	wordnet
PORTVERSION=	1.4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pywordnet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pywordnet-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

RUN_DEPENDS=	${WORDNETBASE}/lexnames:${PORTSDIR}/textproc/wordnet

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py
WORDNETBASE?=	${LOCALBASE}/share/wordnet-${WORDNET_VERSION}
WORDNET_VERSION?=	1.7

post-patch:
	@${SED} -e 's|/usr/local/wordnet1.6|${WORDNETBASE}|g' \
		-e 's|os.path.join(WNHOME.*))|WNHOME)|g' ${WRKSRC}/wordnet.py \
		> ${WRKSRC}/wordnet.py.tmp && ${CAT} ${WRKSRC}/wordnet.py.tmp \
		> ${WRKSRC}/wordnet.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install -c -O1 --prefix=${PREFIX}

.include <bsd.port.mk>
