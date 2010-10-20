# New ports collection makefile for:    mod_auth_cas
# Date created:            				Thursday December 24, 2009
# Whom:                				 	Kimo <kimor79@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_cas
PORTVERSION=	1.0.8
CATEGORIES=	www
#MASTER_SITES=	https://www.ja-sig.org/svn/cas-clients/mod_auth_cas/tags/mod_auth_cas-1.0.8/src/
# SVN tags only, *sigh*
DISTFILES=	mod_auth_cas.c mod_auth_cas.h
DIST_SUBDIR=	mod_auth_cas
EXTRACT_ONLY=

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 2.x module that supports the CASv1 and CASv2 protocols

MAKE_JOBS_SAFE=	yes

NO_WRKSUBDIR=	yes

USE_APACHE=	2.0+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/mod_auth_cas.c ${WRKSRC}/mod_auth_cas.c
	${CP} ${DISTDIR}/${DIST_SUBDIR}/mod_auth_cas.h ${WRKSRC}/mod_auth_cas.h

.include <bsd.port.mk>
