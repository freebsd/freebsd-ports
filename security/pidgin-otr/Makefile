# ex:ts=8
# New ports collection makefile for:	Gaim-OTR
# Date created:				2004-12-17
# Whom:					Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	otr
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.cypherpunks.ca/otr/ \
		http://www.xelerance.com/mirror/otr/
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@mcdermottroe.com
COMMENT=	Allows deniable private conversations using GAIM

BUILD_DEPENDS=	${LOCALBASE}/include/gaim/config.h:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim
LIB_DEPENDS=	otr:${PORTSDIR}/security/libotr \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libotr-prefix=${LOCALBASE}/lib \
		--with-libotr-inc-prefix=${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
