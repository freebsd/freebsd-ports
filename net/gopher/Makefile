# New ports collection makefile for:	gopher
# Date created:		11 Dec 1994
# Whom:			ats (original)
#
# $FreeBSD$
#

PORTNAME=	gopher
PORTVERSION=	3.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.quux.org/give-me-gopher/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	gopher.1 gophfilt.1
MAN5=	gopherd.conf.5 gopherrc.5
MAN8=	gopherd.8 gopherindex.8

pre-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | xargs ${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,'

.include <bsd.port.mk>
