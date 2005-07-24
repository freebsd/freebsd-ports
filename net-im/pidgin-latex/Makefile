# New ports collection makefile for:	Gaim-LaTeX
# Date created:				2005-06-22
# Whom:					Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	latex
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Display LaTeX output in your IMs

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim \
		latex:${PORTSDIR}/print/teTeX \
		convert:${PORTSDIR}/graphics/ImageMagick

CFLAGS+=	"-fPIC"
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_BZIP2=	yes

PLIST_FILES=	lib/gaim/LaTeX.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/LaTeX.so ${PREFIX}/lib/gaim

.include <bsd.port.mk>
