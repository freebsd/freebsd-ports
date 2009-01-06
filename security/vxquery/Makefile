# New ports collection makefile for:	vxquery
# Date created:				2004/02/11
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vxquery
PORTVERSION=	0.2.1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.vuxml.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VuXML Query Tool

USE_BZIP2=	YES
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/object/vxquery ${PREFIX}/bin/vxquery

.include <bsd.port.mk>
