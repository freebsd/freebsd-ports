# New ports collection makefile for:	sysutils/bubblemon2
# Date created:				08 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	bubblemon2
PORTVERSION=	2.0.4
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	bubblemon
DISTNAME=	bubblemon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system CPU and memory load monitor for GNOME2

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop2

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomepanel gnomeprefix gnometarget intlhack
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		bubblemon-gnome2.1
MANLANG=	"" hu sv

PORTDOCS=	AUTHORS COPYING ChangeLog FAQ PROFILING TRANSLATIONS NEWS README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
