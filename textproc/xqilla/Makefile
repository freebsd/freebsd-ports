# Created by: vanilla@
# $FreeBSD$

PORTNAME=	xqilla
PORTVERSION=	2.3.0
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	XQilla-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An XQuery and XPath2 library

LIB_DEPENDS=	xerces-c.3:${PORTSDIR}/textproc/xerces-c3

USE_GMAKE=	yes
USES=		perl5
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
