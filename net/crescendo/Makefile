# New ports collection makefile for:    crescendo
# Date created:         27.Apr 2000
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#   $MCom: ports/net/crescendo/Makefile,v 1.6 2007/05/30 18:26:15 mezz Exp $
#

PORTNAME=	crescendo
PORTVERSION=	1.1.7
PORTREVISION=	11
CATEGORIES=	net gnome
# Master Site broken
#MASTER_SITES=	http://crescendo.lyrical.net/files/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gnome frontend for tinyfuge

RUN_DEPENDS=	tf:${PORTSDIR}/net/tinyfugue

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-compile-warnings=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-g
PLIST_SUB=	DOCDIR=share/doc/${PORTNAME}

USE_XORG=	x11 sm ice xi xext
USE_GNOME=	gnomelibs

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|txtOutput|txtNotepadOutput|g' \
		${WRKSRC}/src/notepad.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog HACKING INSTALL NEWS \
		README README.BINARY TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
