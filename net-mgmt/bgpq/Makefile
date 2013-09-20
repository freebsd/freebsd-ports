# Created by: Alexandre Snarskii <snar@paranoia.ru>
# $FreeBSD$

PORTNAME=	bgpq
PORTVERSION=	1.0.9.9
CATEGORIES=	net-mgmt
MASTER_SITES=	http://snar.spb.ru/prog/bgpq/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Bgpq - lightweight access-list generator for Cisco routers

MAN8=		bgpq.8
PLIST_FILES=	bin/bgpq

GNU_CONFIGURE=	yes

NO_STAGE=	yes
post-install:
	${STRIP_CMD} ${PREFIX}/bin/bgpq

.include <bsd.port.mk>
