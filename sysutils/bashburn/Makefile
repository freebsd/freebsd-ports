# New ports collection makefile for:	sysutils/bashburn
# Date created:				24 august 2007
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	bashburn
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	BashBurn-${PORTVERSION}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	CD burning bash script

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
USE_CDRTOOLS=	yes

OPTIONS=	CDRDAO "Disk-At-Once Recording" on \
		DVDTOOLS "Frontend to master DVD media" on \
		EJECT "Ejecting the CD/DVD drive" on \
		FLAC "Free Lossless Audio Codec" on \
		LAME "LGPL MP3 encoder" on \
		MPG123 "Mpg audio player (for MP3-decompression)" on \
		NORMALIZE "An audio file volume normalizer" on \
		SUDO "To allow non-privileged users to burn CD's" on \
		VORBIS "ogg/vorbis audio encoding/decoding" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CDRDAO)
RUN_DEPENDS+=	${LOCALBASE}/bin/cdrdao:${PORTSDIR}/sysutils/cdrdao
.endif
.if !defined(WITHOUT_DVDTOOLS)
RUN_DEPENDS+=	${LOCALBASE}/bin/dvd+rw-mediainfo:${PORTSDIR}/sysutils/dvd+rw-tools
.endif
.if !defined(WITHOUT_EJECT)
RUN_DEPENDS+=	${LOCALBASE}/sbin/eject:${PORTSDIR}/sysutils/eject
.endif
.if !defined(WITHOUT_FLAC)
RUN_DEPENDS+=	${LOCALBASE}/bin/flac:${PORTSDIR}/audio/flac
.endif
.if !defined(WITHOUT_LAME)
RUN_DEPENDS+=	${LOCALBASE}/bin/lame:${PORTSDIR}/audio/lame
.endif
.if !defined(WITHOUT_MPG123)
RUN_DEPENDS+=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123
.endif
.if !defined(WITHOUT_NORMALIZE)
RUN_DEPENDS+=	${LOCALBASE}/bin/normalize:${PORTSDIR}/audio/normalize
.endif
.if !defined(WITHOUT_SUDO)
RUN_DEPENDS+=	${LOCALBASE}/bin/sudo:${PORTSDIR}/security/sudo
.endif
.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	${LOCALBASE}/bin/ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc/|${PREFIX}/etc/|' \
		${WRKSRC}/BashBurn.sh
	@${REINPLACE_CMD} 's|/usr/local/BashBurn|${DATADIR}|' \
		${WRKSRC}/bashburnrc

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/BashBurn.sh ${PREFIX}/bin/bashburn
	${INSTALL_DATA} ${WRKSRC}/bashburnrc ${PREFIX}/etc/bashburnrc.sample
	cd ${WRKSRC} && ${CP} -Rfp \
		burning config convert lang menus misc func ${DATADIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
