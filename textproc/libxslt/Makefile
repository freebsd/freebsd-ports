# New ports collection makefile for:	libxslt
# Date created:				9th February 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxslt
PORTVERSION=	1.0.12
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libxslt

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

MAN4=		libexslt.4 libxslt.4
MAN1=		xsltproc.1

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON:=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON:="@comment "
PKGNAMESUFFIX=	-nopython
.endif

.if !defined(WITHOUT_PYTHON)
pre-extract:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you don't want Python support, add WITHOUT_PYTHON=yes to command line"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
