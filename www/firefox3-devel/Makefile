# ex:ts=8
#
# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=		phoenix
PORTVERSION=		0.3
PORTREVISION=		0
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=	alane@freebsd.org # will change to trevor@ soon

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2 \
		perl5.8.0:${PORTSDIR}/lang/perl5.8

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=		yes
USE_GMAKE=		yes
#USE_AUTOCONF_VER=	213
GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/mozilla

.include <bsd.port.pre.mk>

post-extract:
	${SED} -e 's|@X11BASE@|${X11BASE}|'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|'	\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig

.include <bsd.port.post.mk>

#EOF
