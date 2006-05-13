# ex:ts=8
# New ports collection makefile for:	xmlpp
# Date created:			May 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlpp
PORTVERSION=	0.7a
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://0xff.at/download/gpl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Parser and Validator

FETCH_CMD=	/usr/bin/fetch
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local/share|$$(datadir)|g'
	@${RM} ${WRKSRC}/config.cache

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
