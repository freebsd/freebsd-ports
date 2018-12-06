# Created by: ijliao
# $FreeBSD$

PORTNAME=	sitebar
PORTVERSION=	3.3.9
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/SiteBar/${PORTVERSION}
DISTNAME=	SiteBar-${PORTVERSION}

MAINTAINER=	gunter@six-two.net
COMMENT=	The Bookmark Server for Personal and Team Use

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

IGNORE_WITH_PHP=	71 72 73

USES=		php:web tar:bzip2
USE_PHP=	mysql pcre
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
