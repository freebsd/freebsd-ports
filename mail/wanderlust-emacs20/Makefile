# New ports collection makefile for:	Wanderlust (for emacs20)
# Date created:		7 Apr 1999
# Whom: 		MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

MAINTAINER=	nobutaka@nobutaka.com

MASTERDIR=	${.CURDIR}/../../mail/wanderlust-emacs

EMACS_PORT_NAME=	emacs20

IS_SLAVE=		yes

.if !defined(WITHOUT_X11) && !defined(WITHOUT_BITMAP)
RUN_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/bitmap/bitmap.el:${PORTSDIR}/editors/bitmap-emacs20
.endif

.include <${MASTERDIR}/Makefile>
