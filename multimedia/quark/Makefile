# New ports collection makefile for:	multimedia/quark
# Date created:		21 Jul 2003
# Whom:			Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$

PORTNAME=	quark
PORTVERSION=	3.11
PORTREVISION=	3
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://quark.sunsite.dk/

MAINTAINER=	rael@vectorstar.net
COMMENT=	Quark is an audio player, for geeks, by geeks

LIB_DEPENDS=	xine.9:${PORTSDIR}/multimedia/libxine

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=    yes
USE_GNOME=      gnomehack gnomeprefix gnomevfs2
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=           AUTHORS COPYING INSTALL README

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} pkg-message

.include <bsd.port.mk>
