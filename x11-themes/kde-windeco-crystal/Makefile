# Created by: decept
# $FreeBSD$

PORTNAME=	crystal
PORTVERSION=	1.0.7
PORTREVISION=	5
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde-windeco-
DISTNAME=	13969-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent KDE window decoration

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_AUTOTOOLS=	libtool
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_LATEST_LINK=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
