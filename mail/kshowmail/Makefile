## New ports collection makefile for:	kshowmail
# Date created:			Sat Oct 18 14:01:21 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kshowmail
PORTVERSION=		3.1.0
PORTREVISION=		4
CATEGORIES=		mail kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		markus@FreeBSD.org
COMMENT=		POP3 mail checker for KDE

LIB_DEPENDS=		mimelib.1:${PORTSDIR}/deskutils/kdepim3

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${RM} ${WRKSRC}/kshowmail/OptionDlg.h ${WRKSRC}/kshowmail/OptionDlg.cpp

.include <bsd.port.mk>
