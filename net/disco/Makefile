# New ports collection makefile for:	disco
# Date created:				08.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	disco
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.altmode.com/disco/
DISTNAME=	${PORTNAME}-${PORTVERSION}bsd

MAINTAINER=	krion@FreeBSD.org
COMMENT=	IP discovery and fingerprinting utility

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
