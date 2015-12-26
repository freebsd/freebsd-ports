# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Kwiki
PORTVERSION=	0.39
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	http://www.kwiki.org/downloads/ \
		LOCAL/clsung/${PORTNAME}
PKGNAMEPREFIX=	p5-
DISTNAME=	kwiki-trunk-20070327

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Kwiki Wiki Building Framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		shebangfix
SHEBANG_FILES=	src/plugins/cfedde/bin/rippod
KWIKIDIR?=	kwiki
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB=	KWIKIDIR=${KWIKIDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${KWIKIDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${KWIKIDIR})

.include <bsd.port.mk>
