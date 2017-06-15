# Created by: tundra
# $FreeBSD$

PORTNAME=	tbku
PORTVERSION=	1.120
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tbku/

MAINTAINER=	tbku@tundraware.com
COMMENT=	Tool For Incremental And Imaging Backups

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in WHATSNEW.txt tbku-license.txt tbku.html tbku.pdf tbku.ps tbku.txt \
	Imaging-FreeBSD-With-tbku.txt     Imaging-FreeBSD-With-tbku.html \
	Imaging-FreeBSD-With-tbku.pdf     Imaging-FreeBSD-With-tbku.ps  \
	Imaging-SUSE-Linux-With-tbku.txt  Imaging-SUSE-Linux-With-tbku.html \
	Imaging-SUSE-Linux-With-tbku.pdf  Imaging-SUSE-Linux-With-tbku.ps
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
