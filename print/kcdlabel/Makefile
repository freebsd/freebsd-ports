# New ports collection makefile for:	kcdlabel
# Date created:			Mon Dec 29 03:01:39 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kcdlabel
PORTVERSION=		2.12
PORTREVISION=	1
CATEGORIES=		print kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION}-KDE3

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		Create covers, labels and booklets for your CD cases

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
