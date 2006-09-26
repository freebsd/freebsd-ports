# New ports collection makefile for:	Template Lite
# Date created:		2006-09-21
# Whom:	      		Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	templatelite
PORTVERSION=	1.90
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	template_lite_${PORTVERSION}

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	A smaller, faster alternative to the Smarty template engine

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/src && ${FIND} * | ${TAR} cTf - - | ${TAR} xUCf ${DATADIR} -
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} * -type f -exec ${INSTALL_DATA} {} ${DOCSDIR} \;
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
