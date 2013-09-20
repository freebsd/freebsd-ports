# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	bashburn
PORTVERSION=	2.1.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	BashBurn-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	CD burning bash script

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

NO_BUILD=	yes

OPTIONS_DEFINE=	CDRDAO DVDTOOLS EJECT FLAC LAME MPG123 NORMALIZE SUDO VORBIS
OPTIONS_DEFAULT=	CDRDAO DVDTOOLS EJECT FLAC LAME MPG123 NORMALIZE SUDO VORBIS
CDRDAO_DESC=	Disk-At-Once Recording
DVDTOOLS_DESC=	Frontend to master DVD media
EJECT_DESC=	Ejecting the CD/DVD drive
NORMALIZE_DESC=	An audio file volume normalizer
SUDO_DESC=	To allow non-privileged users to burn CD's

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDRDAO}
RUN_DEPENDS+=	${LOCALBASE}/bin/cdrdao:${PORTSDIR}/sysutils/cdrdao
.endif
.if ${PORT_OPTIONS:MDVDTOOLS}
RUN_DEPENDS+=	${LOCALBASE}/bin/dvd+rw-mediainfo:${PORTSDIR}/sysutils/dvd+rw-tools
.endif
.if ${PORT_OPTIONS:MEJECT}
RUN_DEPENDS+=	${LOCALBASE}/sbin/eject:${PORTSDIR}/sysutils/eject
.endif
.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	${LOCALBASE}/bin/flac:${PORTSDIR}/audio/flac
.endif
.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	${LOCALBASE}/bin/lame:${PORTSDIR}/audio/lame
.endif
.if ${PORT_OPTIONS:MMPG123}
RUN_DEPENDS+=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123
.endif
.if ${PORT_OPTIONS:MNORMALIZE}
RUN_DEPENDS+=	${LOCALBASE}/bin/normalize:${PORTSDIR}/audio/normalize
.endif
.if ${PORT_OPTIONS:MSUDO}
RUN_DEPENDS+=	${LOCALBASE}/bin/sudo:${PORTSDIR}/security/sudo
.endif
.if ${PORT_OPTIONS:MVORBIS}
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

.include <bsd.port.mk>
