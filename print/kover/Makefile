# New ports collection makefile for:	kover
# Date created:			Mon Dec 29 05:07:17 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kover
PORTVERSION=		2.9.3
PORTREVISION=	1
CATEGORIES=		print kde
MASTER_SITES=		http://lisas.de/kover/

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		WYSIWYG CD cover printer

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
