# New ports collection makefile for:    xdvi
# Version required:     patchlevel 20
# Date created:         1 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.15 1995/06/13 20:59:04 jmz Exp $
#

DISTNAME=	xdvi-20
PKGNAME=	xdvi-pl20
CATEGORIES+=	printing
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/	\
		ftp://crl.dec.com/pub/X11/contrib/applications/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
USE_GMAKE=	yes
IS_INTERACTIVE=	yes

XMKMF=		xmkmf

do-install: 
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/bin
	@(cd ${WRKSRC}; ${GMAKE} install.man \
		MANDIR=${PREFIX}/man/man1 MANSUFFIX=1)
	@(cd ${WRKSRC}; ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} xdvi.man)
	@(cd ${WRKSRC}; ${GMAKE} -f Makefile install BINDIR=${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 755 -o bin MakeTeXPK ${PREFIX}/bin)

.include <bsd.port.mk>
