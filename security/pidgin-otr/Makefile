# ex:ts=8
# New ports collection makefile for:	Gaim-OTR
# Date created:				2004-12-17
# Whom:					Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	otr
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	http://www.cypherpunks.ca/otr/ \
		http://www.xelerance.com/mirror/otr/
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@mcdermottroe.com
COMMENT=	Allows deniable private conversations using GAIM

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim
LIB_DEPENDS=	otr:${PORTSDIR}/security/libotr \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s|%%X11BASE%%|${X11BASE}|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/gaim-otr.so ${PREFIX}/lib/gaim

.include <bsd.port.mk>
