# New ports collection makefile for:	mbuffer
# Date created:				Dec 14 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mbuffer
PORTVERSION=	2011.01.19
CATEGORIES=	misc
MASTER_SITES=	http://www.maier-komor.de/software/mbuffer/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A tool for buffering data streams

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	SHELL=${SH}

PLIST_FILES=	bin/mbuffer

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},' ${WRKSRC}/configure

.include <bsd.port.post.mk>
