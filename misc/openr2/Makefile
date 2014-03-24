# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openr2
PORTVERSION=	1.3.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	MFC/R2 call setup library

BUILD_DEPENDS=	${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
USE_LDCONFIG=	yes

.include <bsd.port.mk>
