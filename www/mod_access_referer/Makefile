# New ports collection makefile for:	mod_access_referer
# Date created:			18 Oct 2000
# Whom:				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	mod_access_referer
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/accessreferer/accessreferer/${PORTVERSION}
DIST_SUBDIR=	apache

PATCH_SITES=    ${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	accessreferer
PATCHFILES=	mod_access_referer_1.0.2_third_part_patch.txt
PATCH_DIST_STRIP=	-l

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Provides access control based on Referer HTTP header for Apache

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
PORTDOCS=		HACKING LICENSE.txt ChangeLog README TODO mod_access_referer.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
