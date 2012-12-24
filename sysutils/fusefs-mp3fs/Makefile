# Created by: Stefan Rumetshofer
# $FreeBSD$

PORTNAME=	mp3fs
PORTVERSION=	0.32
CATEGORIES=	sysutils audio
MASTER_SITES=	https://github.com/downloads/khenriks/${PORTNAME}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	sterum@overrider.at
COMMENT=	FUSE-based filesystem for transcoding flac to mp3 on the fly

LIB_DEPENDS=	mp3lame:${PORTSDIR}/audio/lame \
		FLAC:${PORTSDIR}/audio/flac \
		id3tag:${PORTSDIR}/audio/libid3tag

FETCH_CMD=	fetch -Fpr

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_FUSE=	yes
MAN1=		mp3fs.1
PLIST_FILES=	bin/mp3fs

.include <bsd.port.mk>
