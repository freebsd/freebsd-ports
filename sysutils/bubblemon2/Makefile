# New ports collection makefile for:	sysutils/bubblemon2
# Date created:				08 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	bubblemon2
PORTVERSION=	2.0.9
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	SAVANNAH/bubblemon
DISTNAME=	bubblemon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system CPU and memory load monitor for GNOME2

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop

USE_GNOME=	gnomehack gnomepanel gnomeprefix gnometarget intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`" \
		LDFLAGS="-L${LOCALBASE}/lib `pkg-config --libs libgnomeui-2.0`"

MAN1=		bubblemon-gnome2.1
MANLANG=	"" hu sv

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog FAQ PROFILING TRANSLATIONS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
