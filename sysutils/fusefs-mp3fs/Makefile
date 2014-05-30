# Created by: Stefan Rumetshofer
# $FreeBSD$

PORTNAME=	mp3fs
PORTVERSION=	0.9
PORTEPOCH=	1
CATEGORIES=	sysutils audio
MASTER_SITES=	https://github.com/khenriks/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	sterum@overrider.at
COMMENT=	FUSE-based filesystem for transcoding flac to mp3 on the fly

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
