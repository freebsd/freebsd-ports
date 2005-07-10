# New ports collection makefile for:	less
# Date created:		8 Nov 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	less
PORTVERSION=	382
CATEGORIES=	sysutils
MASTER_SITES=	http://www.greenwoodsoftware.com/%SUBDIR%/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	less
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jharris@widomaker.com
COMMENT=	A better pager utility

USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.sig

PLIST_FILES=	bin/less bin/lesskey bin/lessecho

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
MAN1=		less.1 lesskey.1

.if defined(COLOUR_LESS) || defined(COLOR_LESS)
MAKE_ENV=	CPPFLAGS="-DCOLOUR_LESS"

pre-fetch:
	@${ECHO_MSG} "Making a colour version of less."
.endif

.include <bsd.port.post.mk>
