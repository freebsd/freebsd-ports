# New ports collection makefile for:	edonkey gtk gui link submitter
# Date created:			Sat Feb 23 13:13:08 BRT 2002
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.0.1
CATEGORIES=	net kde
MASTER_SITES=	http://users.aber.ac.uk/tpm01/
PKGNAMESUFFIX=	-gui-gtk-kioslave
DISTNAME=	ed2k_kde2_kioslave

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	ed2k_gui:${PORTSDIR}/net/edonkey-gui-gtk

USE_KDELIBS_VER=	2
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/ed2kslave

pre-configure:
	@${RM} ${WRKSRC}/config.cache

.include <bsd.port.mk>
