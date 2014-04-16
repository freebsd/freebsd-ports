# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Kwiki
PORTVERSION=	0.39
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://www.kwiki.org/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	clsung/${PORTNAME}
PKGNAMEPREFIX=	p5-
DISTNAME=	kwiki-trunk-20070327

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Kwiki Wiki Building Framework

KWIKIDIR?=	kwiki
NO_BUILD=	yes
PLIST_SUB=	KWIKIDIR=${KWIKIDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${KWIKIDIR}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${KWIKIDIR}

.include <bsd.port.mk>
