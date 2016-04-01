# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	mybashburn
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses CD burning bash script

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		cdialog:devel/cdialog \
		cdrecord:sysutils/cdrtools

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	CREDITS ChangeLog FAQ FILES HOWTO INSTALL README TODO

OPTIONS_DEFINE=	CDRDAO DVDTOOLS EJECT FLAC LAME MPG123 NORMALIZE SUDO VORBIS DOCS
OPTIONS_DEFAULT=CDRDAO DVDTOOLS EJECT FLAC LAME MPG123 NORMALIZE SUDO VORBIS

CDRDAO_DESC=	Disk-At-Once Recording
DVDTOOLS_DESC=	Frontend to master DVD media
EJECT_DESC=	Ejecting the CD/DVD drive
NORMALIZE_DESC=	An audio file volume normalizer
SUDO_DESC=	To allow non-privileged users to burn CD's

CDRDAO_RUN_DEPENDS=	cdrdao:sysutils/cdrdao
DVDTOOLS_RUN_DEPENDS=	dvd+rw-mediainfo:sysutils/dvd+rw-tools
EJECT_RUN_DEPENDS=	eject:sysutils/eject
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
MPG123_RUN_DEPENDS=	mpg123:audio/mpg123
NORMALIZE_RUN_DEPENDS=	normalize:audio/normalize
SUDO_RUN_DEPENDS=	sudo:security/sudo
VORBIS_RUN_DEPENDS=	ogg123:audio/vorbis-tools

post-patch:
	@${REINPLACE_CMD} 's|/etc/|${PREFIX}/etc/|; \
		s|/usr/share|${PREFIX}/share|; \
		s|dialog|cdialog|g;' \
		${WRKSRC}/MyBashBurn.sh ${WRKSRC}/etc/mybashburnrc

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/man/mybashburn.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/MyBashBurn.sh ${STAGEDIR}${PREFIX}/bin/mybashburn
	${INSTALL_DATA} ${WRKSRC}/etc/mybashburnrc ${STAGEDIR}${PREFIX}/etc/mybashburnrc.sample
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "burning config convert lang menus misc" ${STAGEDIR}${DATADIR}/)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
