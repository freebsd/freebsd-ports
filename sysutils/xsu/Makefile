# New ports collection makefile for:	xsu
# Date created:				27 Aug 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	xsu
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://xsu.freax.eu.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xsu runs commands as root after prompting for the root password

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
CONFIGURE_ARGS=	--su-pwd-out="Password:"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN8=	xsu.8

DOCS=	CHANGELOG COPYING INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/xsu.desktop \
		${PREFIX}/share/gnome/apps/System
.if !defined(NOPORTDOCS)
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
