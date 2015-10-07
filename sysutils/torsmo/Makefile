# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	torsmo
PORTVERSION=	0.18
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	System monitor that renders text on desktop

DEPRECATED=	no new releases for years, consider using sysutils/conky
EXPIRATION_DATE=	2015-11-08

GNU_CONFIGURE=	yes
USE_XORG=	x11
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/torsmo \
		man/man1/torsmo.1.gz \
		%%EXAMPLESDIR%%/torsmorc.sample
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	XFT DOUBLE_BUFFER DOCS
OPTIONS_DEFAULT=	XFT DOUBLE_BUFFER
DOUBLE_BUFFER_DESC=	Flicker-free operation support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT}
LIB_DEPENDS+=		libXft.so:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.endif

.if ! ${PORT_OPTIONS:MDOUBLE_BUFFER}
CONFIGURE_ARGS+=	--disable-double-buffer
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/torsmorc.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
