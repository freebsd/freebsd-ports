# New ports collection makefile for: nload
# Date created:		24 April 2002
# Whom:			Olivier Tharan <olive@oban.frmug.org>
#
# $FreeBSD$
#

PORTNAME=	nload
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	CRITICAL SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Console application which monitors network traffic in real time

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
MANCOMPRESSED=	yes

LICENSE=	GPLv2

MAN1=		nload.1
PLIST_FILES=	bin/nload

post-patch:
	@${REINPLACE_CMD} -e "s|\(/etc/nload\.conf\)|${PREFIX}\1|" \
		${WRKSRC}/docs/nload.1.in ${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
