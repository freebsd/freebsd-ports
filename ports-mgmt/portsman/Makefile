# New ports collection makefile for:	portsman
# Date created:				18 January 2003
# Whom:					Anselm R. Garbe <anselmg@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	portsman
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	BERLIOS
# temporary
DISTNAME=	${PORTNAME}-${PORTVERSION}-rc2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ncurses based front-end to manage the FreeBSD ports collection

DEPRECATED=		hardwires an ancient version of INDEX
EXPIRATION_DATE=	2011-04-26

MAN1=		portsman.1
MAN5=		portsmanrc.5
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "/^pmanrcdir/s|etc$$|etc/portsman|" \
		${WRKSRC}/config/Makefile.in

.include <bsd.port.mk>
