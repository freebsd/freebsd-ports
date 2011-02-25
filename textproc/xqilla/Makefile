# New ports collection makefile for:		xqilla
# Date created:					Sep 22 2007
# Whom:						vanilla@
#
# $FreeBSD$
#

PORTNAME=	xqilla
PORTVERSION=	2.2.4
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	XQilla-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An XQuery and XPath2 library

LIB_DEPENDS=	xerces-c.3:${PORTSDIR}/textproc/xerces-c3

USE_GMAKE=	yes
USE_PERL5=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

.include <bsd.port.mk>
