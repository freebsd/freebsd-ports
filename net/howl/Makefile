# New ports collection makefile for:	howl
# Date created:			21 July 2003
# Whom:				David Magda <dmagda+howl@ee.ryerson.ca>
# $FreeBSD$
#

PORTNAME=	howl
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES?=	net devel
MASTER_SITES=	http://www.porchdogsoft.com/download/

MAINTAINER=	paul@aps.org
COMMENT=	Zeroconf/Rendezvous implementation

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_GNOME=	gnometarget
USE_LIBTOOL_VER=13
CONFIGURE_ENV+=	CFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
MAN8=		mDNSResponder.8

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread||g' ${WRKSRC}/configure

.include <bsd.port.mk>
