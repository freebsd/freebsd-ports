# New ports collection makefile for:    less
# Version required:     3.*
# Date created:         8 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       less-340
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	less

MAINTAINER=	ache@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		less.1 lesskey.1

EXTRA_PATCH=	patch-ab

pre-clean:
	@${RM} -f ${PATCHDIR}/${EXTRA_PATCH}

.if defined(COLOUR_LESS) || defined(COLOR_LESS)
pre-patch:
	@${ECHO_MSG} "Making a colour version of less."
	@${CP} ${FILESDIR}/${EXTRA_PATCH} ${PATCHDIR}
.endif

.include <bsd.port.mk>
