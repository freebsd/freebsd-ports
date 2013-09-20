# Created by: Brad Huntting <huntting@glarp.com>
# $FreeBSD$

PORTNAME=	qcl
PORTVERSION=	0.6.1
CATEGORIES=	science math
MASTER_SITES=	http://tph.tuwien.ac.at/~oemer/tgz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A quantum computer simulator

NO_STAGE=	yes
do-configure:
	echo 'PREFIX=${PREFIX}' >>${WRKSRC}/Makefile
	cd ${WRKSRC} && make dep

.include <bsd.port.mk>
