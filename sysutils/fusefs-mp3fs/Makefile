# Created by: Stefan Rumetshofer
# $FreeBSD$

PORTNAME=	mp3fs
PORTVERSION=	0.9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils audio
MASTER_SITES=	https://github.com/khenriks/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE-based filesystem for transcoding flac to mp3 on the fly

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libid3tag.so:${PORTSDIR}/audio/libid3tag

FETCH_CMD=	fetch -Fpr

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		fuse pkgconfig
PLIST_FILES=	bin/mp3fs \
		man/man1/mp3fs.1.gz

.include <bsd.port.mk>
