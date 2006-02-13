# New ports collection makefile for:	sendok
# Date created:		18 October 2005
# Whom:			Zak Johnson <zakj@nox.cx>
#
# $FreeBSD$
#

PORTNAME=	sendok
PORTVERSION=	0.9.1
CATEGORIES=	mail
MASTER_SITES=	http://peff.net/sendok/ \
		http://www.cs.virginia.edu/~jrk3g/sendok/

MAINTAINER=	zakj@nox.cx
COMMENT=	Generates qmail email addresses with timed cookies

USE_QMAIL_RUN=	yes

PLIST_FILES=	bin/sendok-check bin/sendok-create

ALL_TARGET=	it

post-patch:
	@${ECHO_CMD} ${CC} ${CFLAGS} >${WRKSRC}/conf-cc

do-install:
.for f in sendok-check sendok-create
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
