# New ports collection makefile for:	fusefs-mp3fs
# Date created: 			18 Feb 2012
# Whom:					Stefan Rumetshofer
# $FreeBSD$
#

PORTNAME=	mp3fs
PORTVERSION=	0.31
CATEGORIES=	sysutils audio
MASTER_SITES=	https://github.com/downloads/khenriks/${PORTNAME}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	sterum@overrider.at
COMMENT=	FUSE-based filesystem for transcoding flac to mp3

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs\
		mp3lame.0:${PORTSDIR}/audio/lame\
		FLAC.10:${PORTSDIR}/audio/flac\
		id3tag.0:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

FETCH_CMD=	fetch -Fpr

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
GNU_CONFIGURE=	yes
MAN1=		mp3fs.1
PLIST_FILES=	bin/mp3fs

.include <bsd.port.mk>
