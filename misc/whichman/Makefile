# New ports collection makefile for:	whichman
# Date created:				6 June 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	whichman
PORTVERSION=	2.4
CATEGORIES=	misc
MASTER_SITES=	http://main.linuxfocus.org/~guido.socher/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Approximate matching utilities to search for manpages and files

USE_REINPLACE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=		ftff.1 ftwhich.1 whichman.1
PLIST_FILES=	bin/ftff bin/ftwhich bin/whichman

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/man:||g' ${WRKSRC}/whichman.c

do-install:
.for name in ftff ftwhich whichman
	${INSTALL_PROGRAM} ${WRKSRC}/${name} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/${name}.1 ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
