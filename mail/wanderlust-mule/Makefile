# New ports collection makefile for:	Wanderlust (for mule)
# Date created:		7 Apr 1999
# Whom: 		MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

MAINTAINER=	nobutaka@nobutaka.com

MASTERDIR=	${.CURDIR}/../../mail/wanderlust-emacs

EMACS_PORT_NAME=	mule
MULE_VER=		2.3

IS_SLAVE=		yes

.if !defined(WITHOUT_X11) && !defined(WITHOUT_BITMAP)
RUN_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/bitmap/bitmap.el:${PORTSDIR}/editors/bitmap-mule
.endif

.include <${MASTERDIR}/Makefile>
