# New ports collection makefile for:	howl
# Date created:			21 July 2003
# Whom:				David Magda <dmagda+howl@ee.ryerson.ca>
# $FreeBSD$
#

PORTNAME=	howl
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES?=	net devel
MASTER_SITES=	http://www.porchdogsoft.com/download/

MAINTAINER=	paul@aps.org
COMMENT=	Zeroconf/Rendezvous implementation

USE_GMAKE=	yes
USE_GNOME=	lthack gnometarget pkgconfig
USE_INC_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
MAN8=		mDNSResponder.8

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-E -e '/^library_includedir[[:space:]]*=/s^\$$[(]includedir[)]/howl^$$(includedir)/howl-${PORTVERSION}^g'

.include <bsd.port.mk>
