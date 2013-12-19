# Created by: Chris Cowart <ccowart@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	pam_require
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://www.splitbrain.org/_media/projects/pamrequire/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ccowart@rescomp.berkeley.edu
COMMENT=	PAM module for restricting access based on unix group or username

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME:S/_/-/}-${PORTVERSION}

PLIST_FILES=	lib/pam_require.so lib/pam_require.so.1

.include <bsd.port.mk>
