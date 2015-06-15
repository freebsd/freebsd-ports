# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	WinFF
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	${_PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert your videos quickly, easily, and all at once

LICENSE=	GPLv3

BUILD_DEPENDS=	fpc:${PORTSDIR}/lang/fpc		\
		lazbuild:${PORTSDIR}/editors/lazarus
LIB_DEPENDS=	libavutil.so:${PORTSDIR}/multimedia/ffmpeg

NO_WRKSUBDIR=	yes
USE_GNOME=	gtk20
_PORTNAME=	${PORTNAME:tl}
DATADIR=	${PREFIX}/share/${_PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${_PORTNAME}
INSTALLS_ICONS=	yes

DESKTOP_ENTRIES=	"${PORTNAME}"	\
			"${COMMENT}"	\
			"${_PORTNAME}"	\
			"${_PORTNAME}"	\
			"AudioVideo;"	\
			true

LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d
LAZARUS_VER=	1.4.0
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/unit1.pas
.for fp in unit1.pas unit4.pas
	${REINPLACE_CMD} -e 's|/usr/bin/|${LOCALBASE}/bin/|g' ${WRKSRC}/${fp}
.endfor

do-build:
	cd ${WRKSRC} && ${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} -B winff.lpr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:tl} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/languages
	${INSTALL_DATA} ${WRKSRC}/presets.xml ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/languages/* ${STAGEDIR}${DATADIR}/languages/
	${INSTALL_MAN} ${WRKSRC}/${_PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/winff-icons/48x48/${_PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
