# New ports collection makefile for:	knemo
# Date created:				Sat Jan 22 00:20:26 CET 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	knemo
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	net kde
MASTER_SITES=	http://www.eris23.de/knemo/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Network monitor for KDE

EXTRA_PATCHES=  ${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
