PORTNAME=	mp3fs
PORTVERSION=	0.91
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils audio
MASTER_SITES=	https://github.com/khenriks/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	stefan.rumetshofer@drei.at
COMMENT=	FUSE-based filesystem for transcoding FLAC to MP3 on the fly

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libid3tag.so:audio/libid3tag \
		libmp3lame.so:audio/lame

USES=		compiler:c11 fuse localbase pkgconfig
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mp3fs \
		man/man1/mp3fs.1.gz

.include <bsd.port.mk>
