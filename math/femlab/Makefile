# New ports collection makefile for:	femlab
# Version required:	v1.1
# Date created:		19 June 1997
# Whom:			Pedro Giffuni
#
# $Id: Makefile,v 1.2 1997/09/17 06:29:25 asami Exp $
#

DISTNAME=	femlab-2d-v1.1
PKGNAME=	femlab-1.1
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.md.chalmers.se/pub/Femlab/	\
		ftp://ftp.ifs.hr/pub/SciUtil/

MAINTAINER=	giffunip@asme.org

BUILD_DEPENDS=	${PREFIX}/lib/libsx.a:${PORTSDIR}/x11/libsx

WRKSRC=         ${WRKDIR}/${PKGNAME}
USE_X_PREFIX=	yes

FEMLAB_HOME=	${PREFIX}/lib/X11/femlab

do-install:
	${MKDIR} ${FEMLAB_HOME}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/femlab ${FEMLAB_HOME}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fsource/meshgen ${FEMLAB_HOME}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fsource/poisson ${FEMLAB_HOME}/bin
	${MKDIR} ${FEMLAB_HOME}/config
	${INSTALL_DATA} ${WRKSRC}/config/modules ${FEMLAB_HOME}/config
	${SED} -e "s|@@FEMLAB_HOME@@|${FEMLAB_HOME}|" <${FILESDIR}/femlab.sh >${PREFIX}/bin/femlab
	chmod +x ${PREFIX}/bin/femlab

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/femlab
	${INSTALL_MAN} ${WRKSRC}/examples/*.fem  ${PREFIX}/share/examples/femlab
	${MKDIR} ${PREFIX}/share/doc/femlab
	${INSTALL_MAN} ${WRKSRC}/docs/manual.dvi ${PREFIX}/share/doc/femlab
	${INSTALL_MAN} ${WRKSRC}/docs/manual.ps  ${PREFIX}/share/doc/femlab
.endif

.include <bsd.port.mk>
