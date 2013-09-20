# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	vxquery
PORTVERSION=	0.2.1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.vuxml.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VuXML Query Tool

USE_BZIP2=	YES
GNU_CONFIGURE=	YES

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/object/vxquery ${PREFIX}/bin/vxquery

.include <bsd.port.mk>
