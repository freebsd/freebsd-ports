# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	torsmo
PORTVERSION=	0.18
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	System monitor that renders text on desktop

GNU_CONFIGURE=	yes
USE_XORG=	x11
CPPFLAGS+=	-I${LOCALBASE}/include
MAN1=		torsmo.1

PLIST_FILES=	bin/torsmo \
		%%EXAMPLESDIR%%/torsmorc.sample
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	XFT DOUBLE_BUFFER DOCS
OPTIONS_DEFAULT=	XFT DOUBLE_BUFFER
DOUBLE_BUFFER_DESC=	Flicker-free operation support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT}
LIB_DEPENDS+=		Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.endif

.if ! ${PORT_OPTIONS:MDOUBLE_BUFFER}
CONFIGURE_ARGS+=	--disable-double-buffer
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/torsmorc.sample ${EXAMPLESDIR}

.include <bsd.port.mk>
