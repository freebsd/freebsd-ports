# Created by: Jim Geovedi <jim@corebsd.or.id>
# $FreeBSD$

PORTNAME=	kripp
PORTVERSION=	0.6.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PACKETSTORM} \
		http://konst.org.ua/download/
MASTER_SITE_SUBDIR=	sniffers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight network password sniffer

USES=		perl5
USE_PERL5=	run

NO_BUILD=	yes
MAN1=		kripp.1
PLIST_FILES=	bin/kripp

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kripp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kripp.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
