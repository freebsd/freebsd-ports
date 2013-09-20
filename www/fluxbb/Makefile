# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	fluxbb
PORTVERSION=	1.4.4
CATEGORIES=	www
MASTER_SITES=	http://fluxbb.org/download/releases/${PORTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A fast and lightweight PHP-powered discussion board

SUB_FILES=	pkg-message
NO_BUILD=	yes
USE_PHP=	yes

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -yxf ${DISTDIR}/${DISTFILES} -C ${WRKSRC}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
