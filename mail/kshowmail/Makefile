## New ports collection makefile for:	kshowmail
# Date created:			Sat Oct 18 14:01:21 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kshowmail
PORTVERSION=		3.1.0
PORTREVISION=	1
CATEGORIES=		mail kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		POP3 mail checker for KDE

LIB_DEPENDS=		mimelib.1:${PORTSDIR}/net/kdenetwork3

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g;' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
