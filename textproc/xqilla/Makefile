# New ports collection makefile for:		xqilla
# Date created:					Sep 22 2007
# Whom:						vanilla@
#
# $FreeBSD$
#

PORTNAME=	xqilla
PORTVERSION=	2.2.0
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	XQilla-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	An XQuery and XPath2 library

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/textproc/xerces-c2:build
LIB_DEPENDS=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2

USE_GMAKE=	yes
USE_PERL5=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-xerces=${XERCESDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
XERCESDIR=	`cd ${PORTSDIR}/textproc/xerces-c2; make -V WRKSRC`

.include <bsd.port.mk>
