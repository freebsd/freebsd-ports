# ex:ts=8
# Ports collection makefile for:  figlet
# Version required: 0.0
# Date created:			  Sat July 20, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	figlet22
PKGNAME=	figlet-2.2
CATEGORIES=	misc
MASTER_SITES=	ftp://wuarchive.wustl.edu/graphics/graphics/misc/figlet/program/unix/ \
		ftp://ftp.funet.fi/pub/unix/tools/figlet/program/unix/ \
		ftp://ftp.internexus.net/pub/figlet/program/unix/ \
		http://people.FreeBSD.org/~obrien/Distfiles/ \
		ftp://nuxi.ucdavis.edu/pub/misc/

MAINTAINER=	obrien@FreeBSD.org

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

.include <bsd.port.mk>
