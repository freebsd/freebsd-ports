# New ports collection makefile for:	imm
# Version required:	3.5a1
# Date created:		13 October 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.18 1998/08/05 09:31:31 asami Exp $
#

DISTNAME=	imm-3.5a1
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm-3.5a1/
DISTFILES=	imm.source.tar.Z
WRKSRC=		${WRKDIR}/mnm

MAINTAINER=	fenner@freebsd.org

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11-toolkits/tk80

USE_X_PREFIX=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/freebsd
	@${CP} ${FILESDIR}/Makefile.work ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.freebsd ${WRKSRC}/src

# The included makefile doesn't have an "install" target.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd/imm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd/immserv ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd/lscomp ${PREFIX}/bin
# and no man pages at all yet.
# But include the very limited documentation
	${MKDIR} ${PREFIX}/share/doc/imm
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/imm
	${INSTALL_DATA} ${WRKSRC}/imm_readme.txt ${PREFIX}/share/doc/imm
.endif
# The sdr plugin is pretty much required.
	${INSTALL_DATA} ${WRKSRC}/sdr2.plugin.S53.image.imm ${PREFIX}/share/doc/imm

.include <bsd.port.mk>
