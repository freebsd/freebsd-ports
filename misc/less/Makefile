# New ports collection makefile for:	less
# Date created:		8 Nov 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	less
PORTVERSION=	354
CATEGORIES=	misc
MASTER_SITES=	http://home.flash.net/~marknu/less/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	less

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500003
FORBIDDEN=	already is in the base system
.endif

GNU_CONFIGURE=	yes
MAN1=		less.1 lesskey.1

.if defined(COLOUR_LESS) || defined(COLOR_LESS)
MAKE_ENV=	CPPFLAGS="-DCOLOUR_LESS"

pre-fetch:
	@${ECHO_MSG} "Making a colour version of less."
.endif

.include <bsd.port.post.mk>
