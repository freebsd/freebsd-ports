# New ports collection makefile for: xcyrBGR
# Date created:		18 Feb 2001
# Whom:			vess /Veselin Slavov/ <vess@btc.net>
#
# $FreeBSD$
#

PORTNAME=	xcyrBGR
PORTVERSION=	1.0
CATEGORIES=	russian
MASTER_SITES=	ftp://aladdin.cblink.net/pub/FreeBSD/X11/cyrillic/ \
		ftp://ftp.cit.bg/pub/FreeBSD/X11/cyrillic/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	vess@btc.net

USE_XPM=	yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400012
MAKE_ENV=	COPT="-fpermissive"
.endif

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xcyrBGR ${PREFIX}/bin/xcyrBGR

.include <bsd.port.post.mk>
