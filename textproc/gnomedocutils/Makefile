# New ports collection makefile for:	gnome-doc-utils
# Date created:				11 November 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomedocutils
PORTVERSION=	0.2.0
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-doc-utils/0.2
DISTNAME=	gnome-doc-utils-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME doc utils

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

PREFIX?=	${X11BASE}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier gnometarget gnomehack libxslt
USE_PYTHON=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-omf-dir=${PREFIX}/share/gnome/omf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xml2po.1

DOCBOOK_VERSION=4.1.2

post-patch:
	@${REINPLACE_CMD} -e 's|4\.2|${DOCBOOK_VERSION}|g' \
		${WRKSRC}/doc/xslt/C/gnome-doc-xslt.xml \
		${WRKSRC}/doc/gnome-doc-make/C/gnome-doc-make.xml

.include <bsd.port.mk>
