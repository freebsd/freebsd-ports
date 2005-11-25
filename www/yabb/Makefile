# New ports collection makefile for:	yabb
# Date created:		20 October 2005
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yabb
PORTVERSION=	2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	YaBB_${PORTVERSION}

MAINTAINER=	infofarmer@gmail.com
COMMENT=	The original free open-source forum written in Perl

USE_ZIP=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
WWWDOCROOT?=	www/data
WWWCGIROOT?=	www/cgi-bin
YABBFILES?=	${WWWDOCROOT}/yabbfiles
YABBGUIDE?=	${WWWDOCROOT}/yabb-guide
YABBCGI?=	${WWWCGIROOT}/yabb2

.if !defined(WITHOUT_YABB_GUIDE)
PLIST_SUB+=	NOYABBGUIDE=""
.else
PLIST_SUB+=	NOYABBGUIDE="@comment "
.endif

PLIST_SUB+=	YABBFILES=${YABBFILES}
PLIST_SUB+=	YABBCGI=${YABBCGI}
PLIST_SUB+=	YABBGUIDE=${YABBGUIDE}
PLIST_SUB+=	DOCSDIR=${DOCSDIR}
PLIST_SUB+=	INSTALL=${INSTALL}

YFILES=		${PREFIX}/${YABBFILES}
YGUIDE=		${PREFIX}/${YABBGUIDE}
YCGI=		${PREFIX}/${YABBCGI}

PORTDOCS=	VERSION.txt README.txt
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${YFILES} ${YGUIDE} ${YCGI}
	${CP} -R ${WRKDIR}/public_html/yabbfiles/ ${YFILES}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${YFILES}
	${CHMOD} -R a+r,o-w,ug+w ${YFILES}

	${CP} -R ${WRKDIR}/cgi-bin/yabb2/ ${YCGI}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${YCGI}
	${CHMOD} -R a+r,ug+w ${YCGI}
	${CHMOD} 755 ${YCGI}/*pl
	${CHMOD} 664 ${YCGI}/Paths.pl

.if !defined(WITHOUT_YABB_GUIDE)
	${CP} -R ${WRKDIR}/Quick-Guide/ ${YGUIDE}
	${LN} -fs ${YGUIDE}/Quick-Guide.html ${YGUIDE}/index.html
	${CHOWN} -R ${YABB_USER}:${WWWGRP} ${YGUIDE}
	${CHMOD} -R go-w,a+r ${YGUIDE}
.endif

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/VERSION.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/README.txt ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
