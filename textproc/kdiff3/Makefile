# New ports collection makefile for:	kdiff3
# Date created:		2003/01/03
# Whom:			Heiner Eichmann <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kdiff3
PORTVERSION=	0.9.70
PORTREVISION=	1
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A KDE3 graphical frontend for diff

CONFIGURE_ARGS+=	--program-transform-name=s,^,,

USE_KDELIBS_VER=	3
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
