# New ports collection makefile for:    xdvi
# Version required:     patchlevel 18
# Date created:         1 October 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	xdvi
PKGNAME=	xdvi-pl18
CATEGORIES+=	printing
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/
DISTFILES=	xdvi.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
IS_INTERACTIVE=	yes

.if !defined(BATCH)
install:
	@echo "===>  Installing for ${DISTNAME}"
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/bin
	@(cd ${WRKSRC}; ${GMAKE} install.man \
		MANDIR=${PREFIX}/man/man1 MANSUFFIX=1)
	@(cd ${WRKSRC}; ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} xdvi.man)
	@(cd ${WRKSRC}; ${GMAKE} -f Makefile install BINDIR=${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 755 -o bin MakeTeXPK ${PREFIX}/bin)
.endif

.include <bsd.port.mk>
