# New ports collection makefile for:	httping
# Date created:				26 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	httping
PORTVERSION=	1.2.5
CATEGORIES=	net
MASTER_SITES=	http://www.vanheusden.com/httping/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A ping-like tool for HTTP requests

MAN1=		httping.1
PLIST_FILES=	bin/httping

CFLAGS+=	-DVERSION=\\\"${PORTVERSION}\\\"

post-patch:
	@${REINPLACE_CMD} -E '/^(DEBUG|CFLAGS)/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
