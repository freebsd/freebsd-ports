# New ports collection makefile for:	 asmail
# Version required:	0.50
# Date created:		15 August 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.5 1998/11/21 07:27:38 steve Exp $
#

DISTNAME=	asmail-0.50
CATEGORIES=	mail afterstep
MASTER_SITES=	ftp://afterstep.foo.net/pub/AfterStep/apps/asmail/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/afterstep/apps/asmail/

MAINTAINER=	brett@peloton.physics.montana.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

PIXMAPS=	e/e-no.xpm e/e0.xpm e/e1.xpm e/e10.xpm e/e11.xpm e/e2.xpm \
		e/e3.xpm e/e4.xpm e/e5.xpm e/e6.xpm e/e7.xpm e/e8.xpm e/e9.xpm \
		monitor-e/monitor-e0.xpm monitor-e/monitor-e1.xpm \
		monitor-e/monitor-e10.xpm monitor-e/monitor-e11.xpm \
		monitor-e/monitor-e2.xpm monitor-e/monitor-e3.xpm \
		monitor-e/monitor-e4.xpm monitor-e/monitor-e5.xpm \
		monitor-e/monitor-e6.xpm monitor-e/monitor-e7.xpm \
		monitor-e/monitor-e8.xpm monitor-e/monitor-e9.xpm \
		monitor-e/monitor-no.xpm std/newmail.xpm \
		std/newmail_s.xpm std/nomail.xpm std/nomail_s.xpm \
		std/oldmail.xpm std/oldmail_s.xpm

MAN1=		asmail.1

post-install:
.for pixmap in ${PIXMAPS}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/${pixmap} ${PREFIX}/include/X11/pixmaps
.endfor
	${MKDIR} ${PREFIX}/share/doc/asmail
	${INSTALL_DATA} ${WRKSRC}/sample.asmailrc ${PREFIX}/share/doc/asmail
	strip ${PREFIX}/bin/asmail

.include <bsd.port.mk>
