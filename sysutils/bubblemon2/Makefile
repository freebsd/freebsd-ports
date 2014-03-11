# Created by: Juan Salaverria <rael@vectorstar.net>
# $FreeBSD$

PORTNAME=	bubblemon2
PORTVERSION=	2.0.17
PORTREVISION=	7
CATEGORIES=	sysutils gnome
MASTER_SITES=	SAVANNAH/bubblemon
DISTNAME=	bubblemon-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	A system CPU and memory load monitor for GNOME2

DEPRECATED=	gnome-panel 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop

USE_GNOME=	gnomehack gnomepanel gnomeprefix intlhack libgnomeui
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`
LDFLAGS+=	-L${LOCALBASE}/lib `pkg-config --libs libgnomeui-2.0`

MAN1=		bubblemon-gnome2.1
MANLANG=	"" hu sv

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog FAQ PROFILING TRANSLATIONS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
