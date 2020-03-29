# Created by: Alexandre Snarskii <snar@paranoia.ru>
# $FreeBSD$

PORTNAME=	bgpq
PORTVERSION=	1.0.9.9
CATEGORIES=	net-mgmt
MASTER_SITES=	http://snar.spb.ru/prog/bgpq/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bgpq - lightweight access-list generator for Cisco routers

LICENSE=	BSD2CLAUSE BSD4CLAUSE # latter for utils.c
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/COPYRIGHT

DEPRECATED=	Use net-mgmt/bgpq3 or net-mgmt/bgpq4
EXPIRATION_DATE=2020-04-30

USES=		tar:tgz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bgpq man/man8/bgpq.8.gz

.include <bsd.port.mk>
