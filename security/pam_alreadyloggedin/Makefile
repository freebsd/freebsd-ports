# New ports collection makefile for:	pam_alreadyloggedin
# Date created:				6 March 2002
# Whom:					green@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pam_alreadyloggedin
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}					\
		http://green.homeunix.org/~green/
MASTER_SITE_SUBDIR=	green

MAINTAINER=	green@FreeBSD.org
COMMENT=	PAM module based on whether a user is already logged in

MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if defined(NOPROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

MAN8=		pam_alreadyloggedin.8

.include <bsd.port.post.mk>
