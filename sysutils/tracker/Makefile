# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/tracker/Makefile,v 1.18 2009/08/08 18:46:41 ahze Exp $

PORTNAME=	tracker
PORTVERSION=	0.6.95
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tracker search tool and indexer metaport

RUN_DEPENDS=	${LOCALBASE}/libexec/trackerd:${PORTSDIR}/sysutils/tracker-client

NO_BUILD=	yes
OPTIONS_DEFINE=	GNOME MSOFFICE
OPTIONS_DEFAULT=GNOME MSOFFICE
GNOME_DESC=	Gnome preferences, panel applet, and search tool
MSOFFICE_DESC=	Search support for Microsoft Office Docs (uses gtk)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
RUN_DEPENDS+=	tracker-applet:${PORTSDIR}/sysutils/tracker-gnome
.endif

.if ${PORT_OPTIONS:MMSOFFICE}
RUN_DEPENDS+=	${LOCALBASE}/lib/tracker/extract-modules/libextract-msoffice.so:${PORTSDIR}/sysutils/tracker-libtrackergtk
.endif

do-install:

.include <bsd.port.mk>
