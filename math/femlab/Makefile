# New ports collection makefile for:	femlab
# Date created:		19 June 1997
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	femlab
PORTVERSION=	1.1
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.md.chalmers.se/pub/Femlab/	\
		ftp://ftp.ifs.hr/pub/SciUtil/
DISTFILES=	femlab-2d-v${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libsx.a:${PORTSDIR}/x11/libsx

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
	${CHMOD} +x ${PREFIX}/bin/femlab

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/femlab
	${INSTALL_MAN} ${WRKSRC}/examples/*.fem  ${PREFIX}/share/examples/femlab
	${MKDIR} ${PREFIX}/share/doc/femlab
	${INSTALL_MAN} ${WRKSRC}/docs/manual.dvi ${PREFIX}/share/doc/femlab
	${INSTALL_MAN} ${WRKSRC}/docs/manual.ps  ${PREFIX}/share/doc/femlab
.endif

.include <bsd.port.mk>
