# New ports collection makefile for:    less
# http://www.flash.net/~marknu/less/
# Version required:     3.*
# Date created:         8 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       less-346
CATEGORIES=	misc
MASTER_SITES=   http://home.flash.net/~marknu/less/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	less

MAINTAINER=	ache@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		less.1 lesskey.1

.if defined(COLOUR_LESS) || defined(COLOR_LESS)
pre-patch:
	@${ECHO_MSG} "Making a colour version of less."
EXTRA_PATCHES=	${FILESDIR}/patch-ab
.endif

.include <bsd.port.mk>
