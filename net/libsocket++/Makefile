# Created by: Narvi <narvi@haldjas.folklore.ee>
# $FreeBSD$

PORTNAME=	libsocket++
PORTVERSION=	1.12.13
CATEGORIES=	net
MASTER_SITES=	http://src.linuxhacker.at/socket++/
DISTNAME=	socket++-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A C++ wrapper library to the sockets

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake autoconf libtool
SCRIPTS_ENV+=	ACLOCAL_FLAGS="-I ${LOCALBASE}/share/aclocal/"

INFO=	socket++

NO_STAGE=	yes
pre-configure:
	@(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${SH} ./autogen)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libsocket++
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/libsocket++
.endif

.include <bsd.port.mk>
