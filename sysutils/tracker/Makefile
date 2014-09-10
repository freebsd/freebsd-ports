# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/tracker/Makefile,v 1.18 2009/08/08 18:46:41 ahze Exp $

PORTNAME=	tracker
PORTVERSION=	0.6.95
PORTREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tracker search tool and indexer metaport

RUN_DEPENDS=	${LOCALBASE}/libexec/trackerd:${PORTSDIR}/sysutils/tracker-client

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes
OPTIONS_DEFINE=	GNOME MSOFFICE
OPTIONS_DEFAULT=GNOME MSOFFICE
GNOME_DESC=	Gnome preferences, panel applet, and search tool
MSOFFICE_DESC=	Search support for Microsoft Office Docs (uses gtk)

GNOME_RUN_DEPENDS=	tracker-applet:${PORTSDIR}/sysutils/tracker-gnome
MSOFFICE_RUN_DEPENDS=	${LOCALBASE}/lib/tracker/extract-modules/libextract-msoffice.so:${PORTSDIR}/sysutils/tracker-libtrackergtk

.include <bsd.port.mk>
