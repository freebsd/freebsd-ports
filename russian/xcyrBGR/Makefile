# New ports collection makefile for: xcyrBGR
# Date created:		18 Feb 2001
# Whom:			vess /Veselin Slavov/ <vess@btc.net>
#
# $FreeBSD$
#

PORTNAME=	xcyrBGR
PORTVERSION=	1.0
CATEGORIES=	russian
MASTER_SITES=	ftp://ftp.slavof.net/pub/FreeBSD/X11/cyrillic/ \
		ftp://mail.partners-bg.org/pub/FreeBSD/X11/cyrillic/ \
		ftp://80.72.71.229/pub/FreeBSD/X11/cyrillic/ \
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	vess@slavof.net
COMMENT=	The bulgarian cyrillic keyboard layout manager for X11

PLIST_FILES=	bin/xcyrBGR
USE_XPM=	yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400012
MAKE_ENV=	COPT="${CXXFLAGS} -fpermissive"
.endif

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xcyrBGR ${PREFIX}/bin/xcyrBGR

.include <bsd.port.post.mk>
