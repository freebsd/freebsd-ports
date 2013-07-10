# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxappearance
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lxde/LXAppearance

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Desktop-independent theme switcher for GTK+

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	gnomehack gtk20 intlhack
MAKE_JOBS_SAFE=	yes

MAN1=		lxappearance.1

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|man po|man|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
