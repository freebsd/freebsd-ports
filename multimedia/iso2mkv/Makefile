# New ports collection makefile for:	iso2mkv
# Date created:			31 Dec 2006
# Whom:				Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iso2mkv
PORTVERSION=	0.8.4
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://5ko.free.fr/dl/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end shell script to convert DVD image, device, or VIDEO_TS to mkv with xvid and ogg or mp3 audio

RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder \
		bash:${PORTSDIR}/shells/bash \
		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix \
		lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		normalize:${PORTSDIR}/audio/normalize

USE_BZIP2=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/iso2mkv

post-patch:
	@${REINPLACE_CMD} -e 's|stat -c %s|stat -f %z|g' \
		${WRKSRC}/iso2mkv
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/iso2mkv
	@${REINPLACE_CMD} -e 's|normalize-audio|normalize|g' \
		${WRKSRC}/iso2mkv

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/iso2mkv ${PREFIX}/bin

.include <bsd.port.mk>
