# New ports collection makefile for:	imm
# Date created:		13 October 1994
# Whom:			wollman
#
# $FreeBSD$
#

PORTNAME=	imm
PORTVERSION=	3.5a1
PORTREVISION=	3
CATEGORIES=	net mbone tk
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm-3.5a1/
DISTNAME=	imm.source
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet Image(or other data) Multicaster (and receiver)

USE_TK=		84
WRKSRC=		${WRKDIR}/mnm

PORTDOCS=	README imm_readme.txt

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/imm_readme.txt ${DOCSDIR}
.endif
# The sdr plugin is pretty much required.
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sdr2.plugin.S53.image.imm ${DATADIR}

.include <bsd.port.post.mk>
