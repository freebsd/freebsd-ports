# Created by: ijliao
# $FreeBSD$

PORTNAME=	sitebar
PORTVERSION=	3.3.9
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/SiteBar/${PORTVERSION}
DISTNAME=	SiteBar-${PORTVERSION}

MAINTAINER=	gunter@six-two.net
COMMENT=	The Bookmark Server for Personal and Team Use

BROKEN_powerpc64=	Does not build

USES=		tar:bzip2
USE_PHP=	mysql pcre
WANT_PHP_WEB=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/www/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \;
	@cd ${WRKSRC} && \
		${FIND} . ! -type d -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	@${FIND} ${STAGEDIR}${DATADIR} ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}

.include <bsd.port.mk>
