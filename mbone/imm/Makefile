# New ports collection makefile for:	imm
# Date created:		13 October 1994
# Whom:			wollman
#
# $FreeBSD$
#

PORTNAME=	imm
PORTVERSION=	3.5a1
CATEGORIES=	mbone tk82
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm-3.5a1/
DISTNAME=	imm.source
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	fenner@FreeBSD.org
COMMENT=	Internet Image(or other data) Multicaster (and receiver)

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/mnm
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
