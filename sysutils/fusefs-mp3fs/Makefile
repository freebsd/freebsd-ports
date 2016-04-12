# Created by: Stefan Rumetshofer
# $FreeBSD$

PORTNAME=	mp3fs
PORTVERSION=	0.91
PORTEPOCH=	1
CATEGORIES=	sysutils audio
MASTER_SITES=	https://github.com/khenriks/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	stefan.rumetshofer@drei.at
COMMENT=	FUSE-based filesystem for transcoding flac to mp3 on the fly

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libFLAC.so:audio/flac \
		libid3tag.so:audio/libid3tag

FETCH_CMD=	fetch -Fpr

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		fuse pkgconfig
PLIST_FILES=	bin/mp3fs \
		man/man1/mp3fs.1.gz

.include <bsd.port.mk>
