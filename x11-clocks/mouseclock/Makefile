# New ports collection makefile for:	mouseclock
# Version required:	1.0
# Date created:		26 August 1997
# Whom:			FURUSAWA, Kazuhisa <furusawa@com.cs.osakafu-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1997/09/09 08:31:06 tg Exp $
#

DISTNAME=	mouseclock-1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/clocks

MAINTAINER=	furusawa@com.cs.osakafu-u.ac.jp

USE_GMAKE=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf
NO_INSTALL_MANPAGES= yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mouseclock
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/mouseclock
.endif

.include <bsd.port.mk>
