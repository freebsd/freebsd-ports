# New ports collection makefile for:	Gaim-OTR
# Date created:				2004-12-17
# Whom:					Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	otr
PORTVERSION=	1.0.1
CATEGORIES=	security net
MASTER_SITES=	http://www.cypherpunks.ca/otr/
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@mcdermottroe.com
COMMENT=	Allows deniable private conversations using GAIM

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim \
		pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim
LIB_DEPENDS=	gpg-error:${PORTSDIR}/security/libgpg-error \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
USE_REINPLACE=	yes

MAN1=		otr_toolkit.1
MLINKS=		otr_toolkit.1 otr_parse.1 \
		otr_toolkit.1 otr_sesskeys.1 \
		otr_toolkit.1 otr_mackey.1 \
		otr_toolkit.1 otr_readforge.1 \
		otr_toolkit.1 otr_modify.1 \
		otr_toolkit.1 otr_remac.1

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/gaim-otr/Makefile \
		${WRKSRC}/libotr/Makefile \
		${WRKSRC}/tools/Makefile
	${REINPLACE_CMD} -e "s|%%X11BASE%%|${X11BASE}|g" \
		${WRKSRC}/gaim-otr/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/gaim-otr.so ${PREFIX}/lib/gaim
	${INSTALL_MAN} ${WRKSRC}/tools/otr_toolkit.1 ${PREFIX}/man/man1
.for P in otr_parse otr_sesskeys otr_mackey otr_readforge otr_modify otr_remac
	${INSTALL_PROGRAM} ${WRKSRC}/${P} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
