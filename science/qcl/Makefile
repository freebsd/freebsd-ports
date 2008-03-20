# ports collection makefile for:	qcl
# Date created:        23 May 2001
# Whom:                Brad Huntting <huntting@glarp.com>
#
# $FreeBSD$
#

PORTNAME=	qcl
PORTVERSION=	0.6.1
CATEGORIES=	science math
MASTER_SITES=	http://tph.tuwien.ac.at/~oemer/tgz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	huntting@glarp.com
COMMENT=	A quantum computer simulator

do-configure:
	echo 'PREFIX=${PREFIX}' >>${WRKSRC}/Makefile
	cd ${WRKSRC} && make dep

.include <bsd.port.mk>
