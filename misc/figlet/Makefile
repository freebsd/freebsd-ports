# ex:ts=8
# Ports collection makefile for:  figlet
# Date created:			  Sat July 20, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#
#	NOTE that the figlet port is purposefully not upgraded to the 2.2.2
#	version until we can determine if the 'Academic Free License 2.1'
#	vs. the Artistic License is better for us.

PORTNAME=	figlet
PORTVERSION=	2.2.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	figlet221

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	SysV banner-like program prints strings in large fancy ASCII art

MAN6=		figlet.6

do-install:
	@ ${MKDIR} ${PREFIX}/share/figlet
	@ ${INSTALL_PROGRAM} ${WRKSRC}/figlet ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/chkfont ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/figlist ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/showfigfonts ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/fonts/*.flf ${PREFIX}/share/figlet
	@ ${INSTALL_DATA} ${WRKSRC}/fonts/*.flc ${PREFIX}/share/figlet
	@ ${INSTALL_MAN} ${WRKSRC}/figlet.6 ${PREFIX}/man/man6
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/figfont.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
