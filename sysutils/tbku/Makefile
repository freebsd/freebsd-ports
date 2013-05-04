# New ports collection makefile for:	tbku
# Date Created:				19 March 2008
# Whom:					tundra
#
# $FreeBSD$
#

PORTNAME=	tbku
PORTVERSION=	1.117
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tbku/

MAINTAINER=	tbku@tundraware.com
COMMENT=	A Tool For Incremental And Imaging Backups

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in WHATSNEW.txt tbku-license.txt tbku.html tbku.pdf tbku.ps tbku.txt \
	Imaging-FreeBSD-With-tbku.txt     Imaging-FreeBSD-With-tbku.html \
	Imaging-FreeBSD-With-tbku.pdf     Imaging-FreeBSD-With-tbku.ps  \
	Imaging-SUSE-Linux-With-tbku.txt  Imaging-SUSE-Linux-With-tbku.html \
	Imaging-SUSE-Linux-With-tbku.pdf  Imaging-SUSE-Linux-With-tbku.ps
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
