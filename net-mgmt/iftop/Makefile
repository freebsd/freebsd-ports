# New ports collection makefile for: 	iftop
# Date created:       			24 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	iftop
PORTVERSION=	0.13
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Network utility for real-time bandwidth usage information

MAN8=		iftop.8

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
DOC_FILES=	README \
		COPYING \
		INSTALL \
		TODO

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' \
		 ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${PREFIX}/man/man8

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
