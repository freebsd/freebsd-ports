# Created by: Francisco Cabrita <include@npf.pt.freebsd.org>
# $FreeBSD$

PORTNAME=	mambo
PORTVERSION=	4.6.5
CATEGORIES=	www
MASTER_SITES=	http://mambo-code.org/gf/download/frsrelease/388/790/
DISTNAME=	MamboV${PORTVERSION}

MAINTAINER=	tabmow@freenode.net
COMMENT=	A dynamic web content management system (CMS)

BROKEN=		Unfetchable due to expired DNS on MASTER_SITES
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-04-10

NO_BUILD=	yes
SUB_FILES+=	pkg-message

OPTIONS_DEFAULT=	MYSQLI
OPTIONS_MULTI=	DB
DB_DESC=	database back-end
OPTIONS_MULTI_DB=	MYSQLI MYSQL
MYSQLI_DESC=	MySQL 4.1+ back-end (use mysqli PHP extension)
MYSQL_DESC=	MySQL back-end (use mysql PHP extension)

NO_STAGE=	yes
.include <bsd.port.options.mk>

USE_PHP=	session zlib gd pdf xml pcre

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
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

.include <bsd.port.mk>
