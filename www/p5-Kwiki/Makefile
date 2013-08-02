# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Kwiki
PORTVERSION=	0.39
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

do-install:
	@${MKDIR} ${PREFIX}/${KWIKIDIR}
	${CP} -RH ${WRKSRC}/ ${PREFIX}/${KWIKIDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${KWIKIDIR}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
		| ${SED} -ne 's,^${WRKSRC},${KWIKIDIR},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
		| ${SED} -ne 's,^${WRKSRC},@dirrm ${KWIKIDIR},p' >> ${TMPPLIST}
	@${SED} -e 's|%%KWIKIDIR%%|${PREFIX}/${KWIKIDIR}|' ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
