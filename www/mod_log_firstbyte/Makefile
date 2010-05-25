# New ports collection makefile for:    mod_log_firstbyte
# Date created:				January 29, 2008
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_log_firstbyte
PORTVERSION=	1.01
CATEGORIES=	www
MASTER_SITES=	http://mod-log-firstbyte.googlecode.com/svn/trunk/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}.c readme.txt

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Log the time between request and the first byte of the response served

MAKE_JOBS_SAFE=  yes

PROJECTHOST=	mod-log-firstbyte
USE_APACHE=	2.0+
MOD=		mod_log_firstbyte
PKGMESSAGE=	${WRKSRC}/readme.txt
DIST_SUBDIR=	${PORTNAME}

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${APXS} -c ${MOD}.c

do-install:
	${APXS} -i -a ${WRKSRC}/${MOD}.la

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
