# New ports collection makefile for:	wb
# Date created:		2 Novermber 1996
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	wb
PORTVERSION=	1.59
CATEGORIES=	mbone
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/wb/
DISTFILES=	i386-wb-1.59.tar.Z

MAINTAINER=	fenner@FreeBSD.org
COMMENT=	A shared drawing (whiteboard) tool using multicast

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes

# ghostscript, ghostscript3, ghostscript4 or ghostscript5 will all do.
USE_GHOSTSCRIPT_RUN=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wb ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wb
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wb
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/wb
	${INSTALL_DATA} ${WRKSRC}/NOTES ${PREFIX}/share/doc/wb
	${INSTALL_DATA} ${WRKSRC}/lblwb.ps ${PREFIX}/share/doc/wb
.endif

.include <bsd.port.post.mk>
