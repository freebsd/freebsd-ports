# Ports collection makefile for:  libsocket++
# Date created:			  Sun Jan 19, 1997
# Whom:				  Narvi <narvi@haldjas.folklore.ee>
#				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	libsocket++
PORTVERSION=	1.12.12
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.linuxhacker.at/linux/downloads/src/
DISTNAME=	socket++-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A C++ wrapper library to the sockets

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	automake:19 autoconf:259 libtool:15
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
