# New ports collection makefile for:	gnewtellium
# Date created:				9 April 2002
# Whom:					haikal
#
# $FreeBSD$

PORTNAME=	gnewtellium
PORTVERSION=	0.05b
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gnutella client

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

PLIST_FILES=	bin/gnewtellium %%DATADIR%%/pixmaps/gnewtellium.xpm
PLIST_DIRS=	%%DATADIR%%/pixmaps %%DATADIR%%

.include <bsd.port.mk>
