# New ports collection makefile for:    xdvi
# Version required:     patchlevel 18
# Date created:         1 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.13 1995/04/21 00:21:41 jmz Exp $
#

DISTNAME=	xdvi
PKGNAME=	xdvi-pl18
CATEGORIES+=	printing
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/
DISTFILES=	xdvi.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
USE_GMAKE=	yes
IS_INTERACTIVE=	yes

XMKMF=		xmkmf

do-install: 
	@echo "===>  Installing for ${DISTNAME}"
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/bin
	@(cd ${WRKSRC}; ${GMAKE} install.man \
		MANDIR=${PREFIX}/man/man1 MANSUFFIX=1)
	@(cd ${WRKSRC}; ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} xdvi.man)
	@(cd ${WRKSRC}; ${GMAKE} -f Makefile install BINDIR=${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 755 -o bin MakeTeXPK ${PREFIX}/bin)

.include <bsd.port.mk>
