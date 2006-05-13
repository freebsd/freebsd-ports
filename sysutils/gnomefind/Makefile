# New ports collection makefile for:	gnomefind
# Date created:				26 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomefind
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-find
DISTNAME=	gnome-find-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical version of the GNU "find" utility

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libglade
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-lgnuregex -L${LOCALBASE}/lib"

MAN1=		gnome-find.1

post-patch:
	@${GREP} -lR "<regex\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<regex\.h>|<gnuregex.h>|g'

.include <bsd.port.mk>
