# New ports collection makefile for:	scim-openvanilla
# Date Created:				3 September 2005
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	scim-openvanilla
PORTVERSION=	0.7.2.20070514
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rafan
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	SCIM OpenVanilla input method (IM)/output filter (OF) framework

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim	\
		${LOCALBASE}/include/OpenVanilla/OpenVanilla.h:${PORTSDIR}/textproc/openvanilla-framework
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libltdl:22
WRKSRC=		${WRKDIR}/${DISTNAME}/Loaders/SCIM
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GETTEXT=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include	\
		OV_MODULEDIR=${PREFIX}/lib/openvanilla/

PLIST_FILES=	lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.a	\
		lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.la	\
		lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.so

.include <bsd.port.mk>
