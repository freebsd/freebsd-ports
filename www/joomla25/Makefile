# New ports collection makefile for:	www/joomla
# Date created:				Sat Out 15, 2005
# Whom:					Francisco Cabrita <include@npf.pt.freebsd.org>
#
# $FreeBSD$

PORTNAME=	joomla
PORTVERSION=	2.5.5
CATEGORIES=	www
MASTER_SITES=	http://downloads.joomlacode.org/frsrelease/7/4/6/74604/
DISTNAME=	Joomla_${PORTVERSION}-Stable-Full_Package

MAINTAINER=	scheidell@FreeBSD.org
COMMENT=	A dynamic web content management system (CMS)

CONFLICTS=	joomla-1.*.*
LATEST_LINK=	joomla25

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	mysql pcre xml zlib session gd pdf json mbstring \
		simplexml zip mysqli
WANT_PHP_WEB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -yxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKSRC}

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${WWWDIR}/{} \; \
			-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;
	@cd ${WRKSRC} && \
		${FIND} . \! -type d -exec ${INSTALL_DATA} {} ${WWWDIR}/{} \; \
			-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;

# maintainer, run after make patch
plist: patch
	${FIND} ${WRKSRC} -type f | ${SORT} | ${SED} -e 's|^${WRKSRC}|%%WWWDIR%%|' > ./pkg-plist
	${FIND} ${WRKSRC} -type d | ${SORT} -fr | ${SED} -e 's|^${WRKSRC}|@dirrm %%WWWDIR%%|' >> ./pkg-plist

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
