# New ports collection makefile for:	torsmo
# Date created:		2004-07-29
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	torsmo
PORTVERSION=	0.18
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	System monitor that renders text on desktop

GNU_CONFIGURE=	yes
USE_XORG=	x11
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
MAN1=		torsmo.1

PLIST_FILES=	bin/torsmo \
		%%EXAMPLESDIR%%/torsmorc.sample
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS=	XFT "XFT support" on \
		DOUBLE_BUFFER "Flicker-free operation support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=		Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.endif

.if defined(WITHOUT_DOUBLE_BUFFER)
CONFIGURE_ARGS+=	--disable-double-buffer
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/torsmorc.sample ${EXAMPLESDIR}

.include <bsd.port.post.mk>
