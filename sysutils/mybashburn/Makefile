# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	mybashburn
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Ncurses CD burning bash script

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		cdialog:${PORTSDIR}/devel/cdialog

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools

NO_BUILD=	yes
MAN1=		mybashburn.1
MANCOMPRESSED=	yes
PORTDOCS=	COPYING CREDITS ChangeLog FAQ FILES HOWTO INSTALL README TODO

OPTIONS_DEFINE=	CDRDAO DVDTOOLS EJECT FLAC LAME MPG123 NORMALIZE SUDO VORBIS DOCS
OPTIONS_DEFAULT=	CDRDAO DVDTOOLS EJECT FLAC LAME MPG123 NORMALIZE SUDO VORBIS
CDRDAO_DESC=	Disk-At-Once Recording
DVDTOOLS_DESC=	Frontend to master DVD media
EJECT_DESC=	Ejecting the CD/DVD drive
NORMALIZE_DESC=	An audio file volume normalizer
SUDO_DESC=	To allow non-privileged users to burn CD's

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDRDAO}
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao
.endif
.if ${PORT_OPTIONS:MDVDTOOLS}
RUN_DEPENDS+=	dvd+rw-mediainfo:${PORTSDIR}/sysutils/dvd+rw-tools
.endif
.if ${PORT_OPTIONS:MEJECT}
RUN_DEPENDS+=	eject:${PORTSDIR}/sysutils/eject
.endif
.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif
.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif
.if ${PORT_OPTIONS:MMPG123}
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.endif
.if ${PORT_OPTIONS:MNORMALIZE}
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.endif
.if ${PORT_OPTIONS:MSUDO}
RUN_DEPENDS+=	sudo:${PORTSDIR}/security/sudo
.endif
.if ${PORT_OPTIONS:MVORBIS}
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc/|${PREFIX}/etc/|; \
		s|/usr/share|${PREFIX}/share|; \
		s|dialog|cdialog|g;' \
		${WRKSRC}/MyBashBurn.sh ${WRKSRC}/etc/mybashburnrc

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/man/mybashburn.1.gz ${MAN1PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/MyBashBurn.sh ${PREFIX}/bin/mybashburn
	${INSTALL_DATA} ${WRKSRC}/etc/mybashburnrc ${PREFIX}/etc/mybashburnrc.sample
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "burning config convert lang menus misc" ${DATADIR}/)

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
