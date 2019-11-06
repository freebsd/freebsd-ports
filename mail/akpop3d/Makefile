# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	akpop3d
PORTVERSION=	0.7.7
CATEGORIES=	mail
MASTER_SITES=	http://www.synflood.at/akpop3d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 daemon aimed to be small and secure

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/akpop3d man/man8/akpop3d.8.gz

OPTIONS_DEFINE=	SSL

SSL_USES=	ssl
SSL_CONFIGURE_WITH=	openssl=${OPENSSLBASE}
SSL_CPPFLAGS=	-I${OPENSSLBASE}/include
SSL_LDFLAGS=	-L${OPENSSLBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/akpop3d ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/akpop3d.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
