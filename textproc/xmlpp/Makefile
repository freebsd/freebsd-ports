# ex:ts=8
# New ports collection makefile for:	xmlpp
# Date created:			May 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlpp
PORTVERSION=	0.7a
CATEGORIES=	textproc
MASTER_SITES=	http://www.root.at/download/gpl/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	XML Parser and Validator

USE_REINPLACE=	yes
FETCH_CMD=	/usr/bin/fetch
USE_GMAKE=	yes
USE_LIBTOOL=	yes

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local/share|$$(datadir)|g'

.include <bsd.port.mk>
