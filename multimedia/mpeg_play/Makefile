# Created by: asami
# $FreeBSD$

PORTNAME=	mpeg_play
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.bsd-geek.de/FreeBSD/distfiles/ \
		ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-patched-src.tar.gz

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Program to play mpeg movies on X displays

NOT_FOR_ARCHS=		aarch64 armv6 armv7 mips mips64
NOT_FOR_ARCHS_REASON=	fails to build: Unknown endianness of architecture

WRKSRC=		${WRKDIR}/mpeg_play
USES=		imake xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/mpeg_play \
		man/man1/mpeg_play.1.gz

pre-patch:
	${CP} ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	${CP} ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include <bsd.port.mk>
