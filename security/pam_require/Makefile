# New ports collection makefile for: pam_require
# Date created:                      30 March 2006
# Whom:                              Chris Cowart <ccowart@rescomp.berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	pam_require
PORTVERSION=	0.6
CATEGORIES=	security
MASTER_SITES=	http://www.splitbrain.org/_media/projects/pamrequire/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ccowart@rescomp.berkeley.edu
COMMENT=	A PAM module for restricting access based on unix group or username

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	lib/pam_require.so lib/pam_require.so.1

.include <bsd.port.mk>
