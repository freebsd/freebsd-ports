# New ports collection makefile for:	howl
# Date created:			21 July 2003
# Whom:				David Magda <dmagda+howl@ee.ryerson.ca>
# $FreeBSD$
#

PORTNAME=	howl
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES?=	net devel
MASTER_SITES=	http://www.porchdogsoft.com/download/

MAINTAINER=	paul@aps.org
COMMENT=	Zeroconf/Rendezvous implementation

USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
CPPFLAGS+=	${PTHREAD_CFLAGS}
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
MAN8=		mDNSResponder.8

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
CPPFLAGS+=	-D_LP64
.endif

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
