# New ports collection makefile for:	ksubeditor
# Date created:         Thu Nov 21 15:05:53 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	KSubeditor
PORTVERSION=	0.2
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME:L}-${PORTVERSION}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A video subtitle editor for KDE

WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22

post-extract:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' -e "s,-lpthread,${PTHREAD_LIBS},g" \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
