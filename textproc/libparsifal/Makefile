# ex:ts=8
# Ports collection makefile for:	libparsifal
# Date created:			Jan 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libparsifal
PORTVERSION=	0.7.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.saunalahti.fi/~samiuus/toni/xmlproc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight XML Parser

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s|||"

.include <bsd.port.mk>
