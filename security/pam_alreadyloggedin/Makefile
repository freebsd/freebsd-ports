# Created by: green@FreeBSD.org
# $FreeBSD$

PORTNAME=	pam_alreadyloggedin
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}					\
		http://green.homeunix.org/~green/
MASTER_SITE_SUBDIR=	green

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PAM module based on whether a user is already logged in

MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.if defined(NO_PROFILE) || defined(NOPROFILE) || defined(WITHOUT_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

MAN8=		pam_alreadyloggedin.8

.include <bsd.port.post.mk>
