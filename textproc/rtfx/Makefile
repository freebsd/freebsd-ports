# New ports collection makefile for:	rtfx
# Date created:		2004-07-29
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	rtfx
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	http://memberwebs.com/stef/software/rtfx/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An RTF to XML converter

LIB_DEPENDS=	mba:${PORTSDIR}/devel/libmba \
		domc:${PORTSDIR}/textproc/domc

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --datarootdir=${PREFIX}
USE_GMAKE=	yes

PLIST_FILES=	bin/rtfx
MAN1=		rtfx.1

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == sparc64
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
