# New ports collection makefile for:	gopher
# Date created:		11 Dec 1994
# Whom:			ats (original)
#
# $FreeBSD$
#

PORTNAME=	gopher
PORTVERSION=	3.0.5
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/give-me-gopher/ \
		http://dl.droso.net/ports/

MAINTAINER=	erwin@lansing.dk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=	gopher.1 gophfilt.1
MAN5=	gopherd.conf.5 gopherrc.5
MAN8=	gopherd.8 gopherindex.8

pre-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | xargs ${REINPLACE_CMD} -e \
		's,<malloc.h>,<stdlib.h>,'

.include <bsd.port.mk>
