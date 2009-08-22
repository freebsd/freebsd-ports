# New ports collection makefile for:	Template Lite
# Date created:		2006-09-21
# Whom:	      		Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	templatelite
PORTVERSION=	2.10
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Template%20Lite/Template%20Lite%20version%20${PORTVERSION}
DISTNAME=	template_lite_${PORTVERSION}

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	A smaller, faster alternative to the Smarty template engine

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes
WRKSRC=	${WRKDIR}/template_lite
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/src && ${FIND} * | ${TAR} cTf - - | ${TAR} xUCf ${DATADIR} -
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} * | ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
