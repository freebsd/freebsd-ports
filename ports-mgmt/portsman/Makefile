# New ports collection makefile for:	portsman
# Date created:				18 January 2003
# Whom:					Anselm R. Garbe <anselmg@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	portsman
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/portsman/
# temporary
DISTNAME=	${PORTNAME}-${PORTVERSION}-rc2

MAINTAINER=	anselmg@t-online.de
COMMENT=	An ncurses based front-end to manage the FreeBSD ports collection

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

MAN1=		portsman.1
MAN5=		portsmanrc.5
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "/^pmanrcdir/s|etc$$|etc/portsman|" \
		${WRKSRC}/config/Makefile.in

.include <bsd.port.post.mk>
