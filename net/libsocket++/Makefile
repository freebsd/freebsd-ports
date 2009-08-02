# Ports collection makefile for:  libsocket++
# Date created:			  Sun Jan 19, 1997
# Whom:				  Narvi <narvi@haldjas.folklore.ee>
#				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	libsocket++
PORTVERSION=	1.12.12
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://src.linuxhacker.at/socket++/
DISTNAME=	socket++-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A C++ wrapper library to the sockets

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake:19 autoconf:262 libtool:22
SCRIPTS_ENV+=	ACLOCAL_FLAGS="-I ${LOCALBASE}/share/aclocal/"

INFO=	socket++

pre-configure:
	@(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${SH} ./autogen)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libsocket++
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/libsocket++
.endif

.include <bsd.port.mk>
