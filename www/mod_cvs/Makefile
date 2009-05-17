# New ports collection makefile for:	mod_cvs
# Date created:				14 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	mod_cvs
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.sub.nu/pub/mod_cvs/ \
		ftp://ftp.isk.kth.se/pub/people/main/mod_cvs/
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A module that makes Apache CVS aware

MAKE_JOBS_SAFE=  yes

CONFLICTS=	apache-contrib-1.*

USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
