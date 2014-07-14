# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	rtfx
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	http://memberwebs.com/stef/software/rtfx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RTF to XML converter

LIB_DEPENDS=	libmba.so:${PORTSDIR}/devel/libmba \
		libdomc.so:${PORTSDIR}/textproc/domc

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --datarootdir=${PREFIX}
USES=		gmake

PLIST_FILES=	bin/rtfx
MAN1=		rtfx.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == sparc64
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
