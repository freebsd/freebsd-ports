# New ports collection makefile for:	clamcour
# Whom:					Milan Obuch
# Date created:				January 13 2006
#
# $FreeBSD$
#

PORTNAME=	clamcour
PORTVERSION=	0.2.3
CATEGORIES=	security mail
MASTER_SITES=	http://www.becrux.com/pages/projects/clamcour/

MAINTAINER=	bsd@dino.sk
COMMENT=	ClamAV courier filter

BUILD_DEPENDS=	courier-config:${PORTSDIR}/mail/courier
LIB_DEPENDS=	clamav.1:${PORTSDIR}/security/clamav

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFIGURE_ARGS=	--with-clamav-config=${LOCALBASE}/bin \
		--with-courier-config=${LOCALBASE}/bin
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

MAN1=		clamcour.1
PLIST_FILES=	libexec/filters/clamcour

.include <bsd.port.mk>
