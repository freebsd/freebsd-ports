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

MAINTAINER=	nectar@FreeBSD.org
COMMENT=	VuXML Query Tool

USE_BZIP2=	YES
USE_SIZE=	YES
GNU_CONFIGURE=	YES

# FreeBSD 5.x systems have expat in the base system.
.include <bsd.port.pre.mk>
.if ${OSVERSION} < 501111
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/object/vxquery ${PREFIX}/bin/vxquery

.include <bsd.port.post.mk>
