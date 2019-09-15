# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	httprint
PORTVERSION=	301
CATEGORIES=	security
MASTER_SITES=	http://net-square.com/zip%20folders/
DISTNAME=	${PORTNAME}_freebsd_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web server fingerprinting tool

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}/freebsd/
USES=		zip

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16
RESTRICTED=	No cost for personal, education and non-commercial use.
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${LN} -s httprint ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
