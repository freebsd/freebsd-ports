# New ports collection makefile for:	comclear
# Date created:		26 November 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	comclear
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.neuro-tech.net/files/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A history cleaner for Netscape Navigator and Communicator

USE_REINPLACE=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
.endif

# Do not install docs by default, see the ifdef'd post-install below.
post-configure:
		${REINPLACE_CMD} 's/^install-data-am:.*/install-data-am:/' ${WRKSRC}/Makefile

.if		!defined(NOPORTDOCS)
post-install:
		cd ${WRKSRC} && ${GMAKE} install-docDATA
.endif

.include <bsd.port.post.mk>
