# Created by: Olivier Tharan <olive@oban.frmug.org>
# $FreeBSD$

PORTNAME=	nload
PORTVERSION=	0.7.4
CATEGORIES=	net
MASTER_SITES=	http://www.roland-riegel.de/nload/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Console application which monitors network traffic in real time

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
MANCOMPRESSED=	yes

MAN1=		nload.1
PLIST_FILES=	bin/nload

post-patch:
	@${REINPLACE_CMD} -e "s|\(/etc/nload\.conf\)|${PREFIX}\1|" \
		${WRKSRC}/docs/nload.1.in ${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
