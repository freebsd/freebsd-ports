# ex:ts=8
# Ports collection makefile for:	pnews
# Date created:			Feb 25, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pnews
PORTVERSION=	2.53
CATEGORIES=	www news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP News Reader

USE_PHP=	yes
WANT_PHP_CGI=	yes
NO_BUILD=	yes

PNEWSDIR?=	${PREFIX}/www/data/pnews

do-install:
	@${MKDIR} ${PNEWSDIR}
	@${CP} -R ${WRKSRC}/* ${PNEWSDIR}
	@${FIND} ${PNEWSDIR} -type f | \
		${SED} -e "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PNEWSDIR} -type d | ${SORT} -r | \
		${SED} -e "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
