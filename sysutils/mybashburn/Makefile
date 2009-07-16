# New ports collection makefile for:	mybashburn
# Date created:				24 jan 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	mybashburn
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Ncurses CD burning bash script

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		cdialog:${PORTSDIR}/devel/cdialog

NO_BUILD=	yes
USE_CDRTOOLS=	yes
MAN1=		mybashburn.1
MANCOMPRESSED=	yes
PORTDOCS=	COPYING CREDITS ChangeLog FAQ FILES HOWTO INSTALL README TODO

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
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao
.endif
.if !defined(WITHOUT_DVDTOOLS)
RUN_DEPENDS+=	dvd+rw-mediainfo:${PORTSDIR}/sysutils/dvd+rw-tools
.endif
.if !defined(WITHOUT_EJECT)
RUN_DEPENDS+=	eject:${PORTSDIR}/sysutils/eject
.endif
.if !defined(WITHOUT_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif
.if !defined(WITHOUT_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif
.if !defined(WITHOUT_MPG123)
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.endif
.if !defined(WITHOUT_NORMALIZE)
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.endif
.if !defined(WITH_SUDO)
RUN_DEPENDS+=	sudo:${PORTSDIR}/security/sudo
.endif
.if !defined(WITHOUT_VORBIS)
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

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
