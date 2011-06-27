# New ports collection makefile for:	www/mambo
# Date created:				Mon Apr 18, 2005
# Whom:					Francisco Cabrita <include@npf.pt.freebsd.org>
#
# $FreeBSD$

PORTNAME=	mambo
PORTVERSION=	4.6.5
CATEGORIES=	www
MASTER_SITES=	http://mambo-code.org/gf/download/frsrelease/388/790/
DISTNAME=	MamboV${PORTVERSION}

MAINTAINER=	tabmow@freenode.net
COMMENT=	A dynamic web content management system (CMS)

NO_BUILD=	yes
SUB_FILES+=	pkg-message

OPTIONS=	MYSQLI "MySQL 4.1+ back-end (use mysqli PHP extension)" on
OPTIONS+=	MYSQL "MySQL back-end (use mysql PHP extension)" off

.include <bsd.port.pre.mk>

USE_PHP=	session zlib gd pdf xml pcre

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_MYSQLI)
USE_PHP+=	mysqli
.endif

.if defined(WITHOUT_MYSQL) && !defined(WITH_MYSQLI)
IGNORE=	needs at least one database back-end
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@if ! (cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTFILES} ${EXTRACT_AFTER_ARGS});\
	then \
		exit 1; \
	fi

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
		@${MKDIR} ${WWWDIR}
		@cd ${WRKSRC} && \
			${FIND} . -type d -exec ${MKDIR} ${WWWDIR}/{} \; \
				-exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;
		@cd ${WRKSRC} && \
			${FIND} . \! -type d -exec ${INSTALL_DATA} {} ${WWWDIR}/{} \; \
				-exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
