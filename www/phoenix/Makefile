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
PORTREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=		alane@freebsd.org # and trevor@freebsd.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2 \
		Xft2.2:${PORTSDIR}/x11-fonts/Xft

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2 \
		perl5.8.0:${PORTSDIR}/lang/perl5.8

PREFIX=		${X11BASE}/lib/${PORTNAME}

USE_BZIP2=		yes
USE_GMAKE=		yes
#USE_AUTOCONF_VER=	213
GNU_CONFIGURE=		yes
CFLAGS+=		${PTHREAD_CFLAGS}
LIBS+=			${PTHREAD_LIBS}
WRKSRC=			${WRKDIR}/mozilla

.include <bsd.port.pre.mk>

.if !defined(PERL_VER) || ${PERL_VER} != 5.8.0
BROKEN=	This port requires Perl 5.8.0.
.endif

post-extract:
	${SED} -e 's|@CFLAGS@|${CFLAGS}|'		\
		-e 's|@LIBS@|${LIBS}|'			\
		-e 's|@X11BASE@|${X11BASE}|'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|'	\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig

post-install:
	${LN} -s ${PREFIX}/bin/phoenix ${X11BASE}/bin/phoenix
	${LN} -s ${PREFIX}/bin/mozilla-config ${X11BASE}/bin/phoenix-config

.include <bsd.port.post.mk>

#EOF
