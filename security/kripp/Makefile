# New ports collection makefile for:	kripp
# Date created:			Apr 23, 2003
# Whom:				Jim Geovedi <jim@corebsd.or.id>
#
# $FreeBSD$
#

PORTNAME=	kripp
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PACKETSTORM} \
		http://konst.org.ua/download/
MASTER_SITE_SUBDIR=	sniffers

MAINTAINER=	jim@corebsd.or.id
COMMENT=	Lightweight network password sniffer

USE_PERL5_RUN=	yes

NO_BUILD=	yes
MAN1=		kripp.1
PLIST_FILES=	bin/kripp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kripp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kripp.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
