# New ports collection makefile for:	ksubeditor
# Date created:         Thu Nov 21 15:05:53 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	KSubeditor
PORTVERSION=	0.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A video subtitle editor for KDE

WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes

post-extract:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
