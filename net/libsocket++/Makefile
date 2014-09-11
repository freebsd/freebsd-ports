# Created by: Narvi <narvi@haldjas.folklore.ee>
# $FreeBSD$

PORTNAME=	libsocket++
PORTVERSION=	1.12.13
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://src.linuxhacker.at/socket++/
DISTNAME=	socket++-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	C++ wrapper library to the sockets

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool makeinfo
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
AUTOMAKE_ARGS=	-a -c
LIBTOOLIZE_ARGS=-i -c

INFO=	socket++

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
