#
# ports collection makefile for:	mysar
# Whom:					Edwin Groothuis <edwin@mavetju.org>
# Date created:				2006-01-10
#
# $FreeBSD$
#

PORTNAME=	mySAR
PORTVERSION=	2.0.11
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysar
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	MySQL Squid Access Report

WRKSRC=		${WRKDIR}/${PORTNAME:L}
USE_MYSQL=	yes
USE_PHP=	mysql
NO_BUILD=	yes

MYSARPREFIX=	mysar
MYSARDIR?=	${PREFIX}/${MYSARPREFIX}
PLIST_SUB=	MYSAR=${MYSARPREFIX}

SUB_FILES=	pkg-message
SUB_LIST=	MYSARDIR=${MYSARDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	${REINPLACE_CMD} -e 's,%%MYSARDIR%%,${MYSARDIR},g' \
		${WRKSRC}/etc/*
	${REINPLACE_CMD} -e 's,%%PHP%%,${LOCALBASE}/bin/php,g' \
		${WRKSRC}/bin/*

	${FIND} ${WRKSRC} -name *.orig -delete
	${FIND} ${WRKSRC} -name *.bak -delete

do-install:
	${MKDIR} ${MYSARDIR}
	${CP} -R ${WRKSRC}/* ${MYSARDIR}
	${CHOWN} -R ${WWWOWN} ${MYSARDIR}/www-templates
	${CHOWN} -R ${WWWOWN} ${MYSARDIR}/smarty-tmp

post-install:
	${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
