# New ports collection makefile for:    mapedit
# Version required:     1.5
# Date created:         Sun Mar 17 17:59:48 MET 1996
# Whom:                 Andreas Klemm <andreas@knobel.gun.de>
#
# $Id$
#

DISTNAME=       mapedit1.5
PKGNAME=        mapedit-1.5
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.boutell.com/pub/boutell/mapedit/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	andreas@knobel.gun.de

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes
DOCDIR=		${PREFIX}/lib/X11/mapedit

pre-install:
	@cat ${FILESDIR}/COPYRIGHT
	@echo ""
	@cat ${WRKSRC}/README
	@echo ""

post-install:
	mkdir -p ${DOCDIR}
	cp ${WRKSRC}/LICENSE ${DOCDIR}
	cp ${WRKSRC}/README ${DOCDIR}
	cp ${WRKSRC}/mapedit.html ${DOCDIR}

.include <bsd.port.mk>
