# New ports collection makefile for:    xdvi
# Version required:     patchlevel 20
# Date created:         1 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.21 1996/11/18 09:54:49 asami Exp $
#

DISTNAME=	xdvi-20
PKGNAME=	xdvi-pl20
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

DIST_SUBDIR=	xdvi	# to share distfiles with japanese/xdvi
USE_IMAKE=	yes
USE_GMAKE=	yes
IS_INTERACTIVE=	yes

XMKMF=		xmkmf

do-install: 
	@${MKDIR} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/bin
	@(cd ${WRKSRC}; ${GMAKE} install.man \
		MANDIR=${PREFIX}/man/man1 MANSUFFIX=1)
	@(cd ${WRKSRC}; ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} xdvi.man)
	@(cd ${WRKSRC}; ${GMAKE} -f Makefile install BINDIR=${PREFIX}/bin)
	@(cd ${WRKSRC}; ${INSTALL_SCRIPT} MakeTeXPK ${PREFIX}/bin)

pre-clean:
	@rm -f ${SCRIPTDIR}/post-install

.include <bsd.port.mk>
