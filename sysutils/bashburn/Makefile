# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	bashburn
PORTVERSION=	3.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://bashburn.dose.se/
DISTNAME=	'index.php?s=file_download&id=25'
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD burning bash script

LICENSE=	GPLv2

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

WRKSRC=		${WRKDIR}/BashBurn-${PORTVERSION}

NO_BUILD=	yes

USES=		shebangfix
SHEBANG_FILES=	BashBurn.sh

OPTIONS_DEFINE=	CDRDAO DVDTOOLS EJECT FLAC LAME MPG123 NORMALIZE SUDO VORBIS DOCS
OPTIONS_DEFAULT=	CDRDAO DVDTOOLS EJECT FLAC LAME MPG123 NORMALIZE SUDO VORBIS
CDRDAO_DESC=	Disk-At-Once Recording
DVDTOOLS_DESC=	Frontend to master DVD media
EJECT_DESC=	Ejecting the CD/DVD drive
NORMALIZE_DESC=	An audio file volume normalizer
SUDO_DESC=	To allow non-privileged users to burn CD's

CDRDAO_RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao
DVDTOOLS_RUN_DEPENDS=	dvd+rw-mediainfo:${PORTSDIR}/sysutils/dvd+rw-tools
EJECT_RUN_DEPENDS=	eject:${PORTSDIR}/sysutils/eject
FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac
LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame
MPG123_RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
NORMALIZE_RUN_DEPENDS=	normalize:${PORTSDIR}/audio/normalize
SUDO_RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo
VORBIS_RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools

post-patch:
	@${REINPLACE_CMD} 's|@@BBROOTDIR@@|${DATADIR}|' \
		${WRKSRC}/BashBurn.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/BashBurn.sh ${STAGEDIR}${PREFIX}/bin/bashburn
.for dir in burning config convert func lang menus misc
	@cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${dir}
.endfor
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name COPYING"
	${INSTALL_MAN} ${WRKSRC}/bashburn_man/bashburn.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
