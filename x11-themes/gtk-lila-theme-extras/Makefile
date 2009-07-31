# New ports collection makefile for:	gtk-lila-theme
# Date Created:				2 Feb 2005
# Whom:					Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	gtk-lila-theme-extras
PORTVERSION=	0.4.5
PORTREVISION=	5
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://lila-theme.uni.cc/files/tarballs/
DISTNAME=	lila-gtk-extras-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ 2.0 Lila additional themes

WRKSRC=		${WRKDIR}/lila-gtk-extras

NO_BUILD=	yes
USE_GNOME=	gtk20
USE_BZIP2=	yes

do-install:
	@${FIND} ${WRKSRC} -type d -depth 1 \
		-exec ${CP} -r "{}" ${PREFIX}/share/themes/ \;

.include <bsd.port.mk>
