# New ports collection makefile for:	tktz
# Date created:				2 May 2006
# Whom:					Alexander Gromnizki
#
# $FreeBSD$
#

PORTNAME=	tktz
PORTVERSION=	0.1
CATEGORIES=	x11-clocks tk84
MASTER_SITES=	http://gromnizki.unixdev.net/soft/

MAINTAINER=	gromnizki@unixdev.net
COMMENT=	A Tcl/Tk-based timezone viewer

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes

do-install:
	@ ${MKDIR} ${PREFIX}/lib/tktz
	@ ${INSTALL_SCRIPT} ${WRKSRC}/tktz ${PREFIX}/lib/tktz
	@ ${LN} -sf ${PREFIX}/lib/tktz/tktz ${PREFIX}/bin
.for file in tktz.help README LICENSE
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/tktz
.endfor

.include <bsd.port.mk>
