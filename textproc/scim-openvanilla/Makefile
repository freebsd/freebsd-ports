# New ports collection makefile for:	scim-openvanilla
# Date Created:				3 September 2005
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	scim-openvanilla
PORTVERSION=	0.7.2.b20060214
CATEGORIES=	textproc
MASTER_SITES=	http://www.csie.org/~llwang/	\
		http://www.infor.org/~llwang/
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	SCIM OpenVanilla input method (IM)/output filter (OF) framework

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim	\
		${X11BASE}/include/OpenVanilla/OpenVanilla.h:${PORTSDIR}/textproc/openvanilla-framework
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libltdl:15
WRKSRC=		${WRKDIR}/${DISTNAME}/Loaders/SCIM
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS=-I${X11BASE}/include	\
		OV_MODULEDIR=${PREFIX}/lib/openvanilla/

.include <bsd.port.mk>
