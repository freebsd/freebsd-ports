# New ports collection makefile for: giFTui
# Date Created:			23 May 2004
# Whom:				Joel Diaz <joeldiaz@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	giFTui
PORTVERSION=	0.4.1
PORTREVISION=	9
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME:L}-${PORTVERSION}
DISTNAME=	giftui-0.4.1

MAINTAINER=	joeldiaz@bellsouth.net
COMMENT=	GTK2 client for giFT daemon

LIB_DEPENDS=	gift.0:${PORTSDIR}/net-p2p/gift

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gconf2 gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

GCONF_SCHEMAS=	giftui.schemas

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^giftuidatadir=.*|giftuidatadir=$${datadir}/giftui|g ; \
		s|^giftuiicondir=.*|giftuiicondir=$${datadir}/pixmaps|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^giftuidocdir =.*|giftuidocdir =${DOCSDIR}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps/||g' \
		${WRKSRC}/data/giftui.desktop

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
