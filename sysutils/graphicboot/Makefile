# New ports collection makefile for:	graphicboot
# Date created:		8 July 2005
# Whom:			Matthew Holder <sixxgate@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	graphicboot
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://matt.sixxgate.com/files/

MAINTAINER=	sixxgate@hotmail.com
COMMENT=	Provides graphical X Window startup to FreeBSD during 'rc'

RUN_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage

USE_MOTIF=	yes
USE_BZIP2=	yes
USE_IMAKE=	yes

MAN1=		graphicboot.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		The graphical boot requires rcorder which is only on FreeBSD 5 or greater.
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
