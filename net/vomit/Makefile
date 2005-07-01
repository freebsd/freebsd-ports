# Ports collection makefile for:  vomit
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vomit
PORTVERSION=	0.2c
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://vomit.xtdnet.nl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Voice over misconfigured internet telephones

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent \
		${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		vomit.1
PLIST_FILES=	bin/vomit

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -Wall -g|@CFLAGS@|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
