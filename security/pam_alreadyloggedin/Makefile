# New ports collection makefile for:	pam_alreadyloggedin
# Date created:				6 March 2002
# Whom:					green@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pam_alreadyloggedin
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}					\
		http://green.bikeshed.org/~green/
MASTER_SITE_SUBDIR=	green

MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"only works on systems with OpenPAM (5.0-CURRENT)"
.endif
MAINTAINER=	green@FreeBSD.org

.if defined(NOPROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

MAN8=		pam_alreadyloggedin.8

.include <bsd.port.post.mk>
