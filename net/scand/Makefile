# New ports collection makefile for:  scand
# Date created:        13 May 2003
# Whom:                sand
#
# $FreeBSD$
#

PORTNAME=	scand
PORTVERSION=	0.14
CATEGORIES=	net
MASTER_SITES=	http://free.babolo.ru/src/ \
		http://www.a.pike.ru/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flood scan detection and blocking daemon

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_RC_SUBR=	scand

MAN8=		scand.8 scandctl.8
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -E -e "s|(install:.*)installscript(.*)|\1\2|; \
		s|-Werror||g" \
		${WRKSRC}/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
