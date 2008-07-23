# New ports collection makefile for:    etoile-nesedah
# Date created:         22 Dec 2006
# Whom:                 alexbl@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nesedah
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.roard.com/gnustep/
PKGNAMEPREFIX=	camaelon-
DISTNAME=	Nesedah.theme
EXTRACT_SUFX=	.tgz

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Etoile Project's Nesedah Camaelon Theme

BROKEN=		conflicts with its own dependency

CONFLICTS=	etoile-camaelon-0.2*

USE_GNUSTEP_SYSTEM_THEMES=	Camaelon:x11-themes/etoile-camaelon

NO_BUILD=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes

WRKSRC=	${WRKDIR}/Nesedah.theme

.include <bsd.port.pre.mk>

do-install:
	@(. ${SYSMAKEDIR}/GNUstep.sh && \
	${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Themes && \
	${CP} -R ${WRKSRC} ${GNUSTEP_PREFIX}/System/Library/Themes/ )

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

install-user:
	@(. ${SYSMAKEDIR}/GNUstep.sh && defaults write Camaelon Theme Nesedah)

deinstall-user:
	@(. ${SYSMAKEDIR}/GNUstep.sh && defaults delete Camaelon Theme)

.include <bsd.port.post.mk>
