# New ports collection makefile for:	sysutils/bubblemon2
# Date created:				08 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$

PORTNAME=	bubblemon2
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	bubblemon
DISTNAME=	bubblemon-${PORTVERSION}

MAINTAINER=	rael@vectorstar.net
COMMENT=	Bubblemon2 is a system CPU and memory load monitor for GNOME2

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop2

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GNOME=      gnomehack gnomeprefix gnomepanel
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		bubblemon-gnome2.1
MANLANG=	"" hu sv

DOCS=		AUTHORS COPYING ChangeLog FAQ PROFILING TRANSLATIONS NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ;' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
