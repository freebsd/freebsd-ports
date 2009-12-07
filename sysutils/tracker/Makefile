# New ports collection makefile for:	tracker
# Date created:		2006-12-09
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/tracker/Makefile,v 1.18 2009/08/08 18:46:41 ahze Exp $
#

PORTNAME=	tracker
PORTVERSION=	0.6.95
CATEGORIES=	sysutils gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tracker search tool and indexer metaport

RUN_DEPENDS=	${LOCALBASE}/libexec/trackerd:${PORTSDIR}/sysutils/tracker-client

NO_BUILD=	yes
OPTIONS=	GNOME "Gnome preferences, panel applet, and search tool" Off \
		MSOFFICE "Enable search for Microsoft Office Docs (uses gtk)" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME)
RUN_DEPENDS+=	tracker-applet:${PORTSDIR}/sysutils/tracker-gnome
.endif

.if defined(WITH_MSOFFICE)
RUN_DEPENDS+=	${LOCALBASE}/lib/tracker/extract-modules/libextract-msoffice.so:${PORTSDIR}/sysutils/tracker-libtrackergtk
.endif

do-install:

.include <bsd.port.post.mk>
