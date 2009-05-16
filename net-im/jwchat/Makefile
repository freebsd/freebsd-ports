# New ports collection makefile for:	jwchat
# Date created:				June 24 2005
# Whom:					Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	jwchat
PORTVERSION=	1.0.b2
PORTREVISION=	1
CATEGORIES=	net-im www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.b,beta,}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Full featured, web-based Jabber client

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3

NO_BUILD=	yes

PLIST_SUB+=	WWW_ROOT=www
SUB_FILES=	pkg-message
SUB_LIST=	WWW_ROOT=www PORTNAME=${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/www ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config.js ${DATADIR}
	${MV} ${WRKSRC}/config.js ${WRKSRC}/config.js.sample
	${CP} -R ${WRKSRC}/ ${PREFIX}/www/${PORTNAME}
	[ ! -f ${PREFIX}/www/${PORTNAME}/config.js ] && \
		${CP} ${DATADIR}/config.js ${PREFIX}/www/${PORTNAME}/config.js || true
	${FIND} ${PREFIX}/www/${PORTNAME} ! -name config.js -print0  | ${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/www/${PORTNAME} -type f -and ! -name config.js -print0 -type f | ${XARGS} -0 ${CHMOD} ${SHAREMODE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
