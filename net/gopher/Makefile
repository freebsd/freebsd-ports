# New ports collection makefile for:	gopher
# Date created:		11 Dec 1994
# Whom:			ats (original)
#
# $FreeBSD$
#

PORTNAME=	gopher
PORTVERSION=	3.0.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/give-me-gopher/ \
		http://dl.droso.net/FreeBSD/distfiles/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Gopher client for access to a distributed document service

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=	gopher.1 gophfilt.1
MAN5=	gopherrc.5

pre-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's,<malloc.h>,<stdlib.h>,'

.include <bsd.port.mk>
