# New ports collection makefile for:	gnomefind
# Date created:				26 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomefind
PORTVERSION=	1.0.2
PORTREVISION=	8
CATEGORIES=	sysutils gnome
MASTER_SITES=	SF/gnome-find/gnome-find-stable/${PORTVERSION}
DISTNAME=	gnome-find-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical version of the GNU "find" utility

DEPRECATED=	Abandoned upstream
EXPIRATION_DATE=	2011-05-01

USE_GNOME=	gnomehack gnomeprefix libglade
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-lgnuregex -L${LOCALBASE}/lib"

MAN1=		gnome-find.1

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "<regex\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<regex\.h>|<gnuregex.h>|g'
.if ${OSVERSION} >= 800023
	${REINPLACE_CMD} -e "s,^int readlink,//int readlink," \
		${WRKSRC}/src/listfile.c
.endif

.include <bsd.port.post.mk>
