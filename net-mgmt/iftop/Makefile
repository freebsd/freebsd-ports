# New ports collection makefile for: 	iftop
# Date created:       			24 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	iftop
PORTVERSION=	0.15
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Network utility for real-time bandwidth usage information

USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes
DOCFILES=	README

MAN8=		iftop.8

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		 ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for doc in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
