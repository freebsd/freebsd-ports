# Ports collection makefile for:  pear-HTTP_FloodControl
# Date created:			  22 Jan 2007
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP_FloodControl
PORTVERSION=	0.1.1
CATEGORIES=	www pear

MAINTAINER=	ditesh@gathani.org
COMMENT=	PEAR classes to detect and protect from attempts to flood a site

BUILD_DEPENDS=	${PEARDIR}/HTTP.php:${PORTSDIR}/www/pear-HTTP
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTTP
FILES=		FloodControl.php FloodControl/Container.php \
		FloodControl/Container/DB.php FloodControl/Container/File.php \
		FloodControl/Container/MDB.php FloodControl/Container/MDB2.php

LATEST_LINK=	pear-HTTP_FloodControl
DOCS=		README LICENSE
OPTIONS=	DB "Enable PEAR::DB support" Off \
		MDB "Enable PEAR::MDB support" Off \
		MDB2 "Enable PEAR::MDB2 support" Off

post-extract:
	${MKDIR} ${WRKSRC}/docs
	${MV} ${WRKSRC}/README ${WRKSRC}/LICENSE ${WRKSRC}/docs
	${MV} ${WRKDIR}/package2.xml ${WRKDIR}/package.xml

.include <bsd.port.pre.mk>

.if defined(WITH_DB)
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_MDB)
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_MDB2)
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
