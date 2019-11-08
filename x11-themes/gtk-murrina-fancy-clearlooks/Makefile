# Created by: pneumann@gmail.com
# $FreeBSD$

PORTNAME=	gtk-murrina-fancy-clearlooks
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	http://home.planet.nl/~bassa052/themes/
DISTNAME=	MurrinaFancyClearlooks_v${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrine fancy clearlooks themes pack

BROKEN=		unfetchable

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.so:x11-themes/gtk-murrine-engine
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.so:x11-themes/gtk-murrine-engine

USES=		gnome

WRKSRC=	${WRKDIR}/MurrinaFancyClearlooks
USE_GNOME=	gtk20
NO_BUILD=	yes

do-install:
	@(cd ${WRKSRC} && for theme in *; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/$$theme/gtk-2.0; \
		cd ${WRKSRC}/$$theme/gtk-2.0/ && for file in *; do\
			${INSTALL_DATA} ${WRKSRC}/$$theme/gtk-2.0/$$file ${STAGEDIR}${PREFIX}/share/themes/$$theme/gtk-2.0; \
		done\
	done;)

.include <bsd.port.mk>
