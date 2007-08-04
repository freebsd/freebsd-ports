# ex:ts=8
# Ports collection Makefile for:	pidgin-otr
# Date created:				2004-12-17
# Whom:					Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	otr
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.cyberdyne.org/~icebrkr/files/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	perlfu@gmail.com
COMMENT=	Allows deniable private conversations using Pidgin

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	otr:${PORTSDIR}/security/libotr \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		purple.1:${PORTSDIR}/net-im/libpurple

USE_XLIB=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-libotr-prefix=${LOCALBASE}/lib \
		--with-libotr-inc-prefix=${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
