# New ports collection makefile for:	dvdwizard
# Date created:		Fri Dec  9 03:01:18 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dvdwizard
PORTVERSION=	0.4.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	udrecsuite
DISTNAME=	udrec_suite-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Automated creation of DVDs with chapters and menus

RUN_DEPENDS=	\
		toolame:${PORTSDIR}/audio/toolame \
		convert:${PORTSDIR}/graphics/ImageMagick \
		seq2:${PORTSDIR}/misc/seq2 \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		transcode:${PORTSDIR}/multimedia/transcode \
		bash:${PORTSDIR}/shells/bash

USE_REINPLACE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

SCRIPT_FILES=	\
		chaptercheck \
		dvdcpics \
		dvdtguess \
		dvdwizard \
		mk_vmgm \
		mk_vtsm \
		mk_vtsm_audio \
		mpgprobe

PLIST_DIR=	\
		%%DATADIR%% \
		%%EXAMPLESDIR%%
PLIST_FILES=	\
		${SCRIPT_FILES:S,^,bin/,} \
		%%DATADIR%%/dvdwizardrc \
		%%EXAMPLESDIR%%/dvdwizard.conf.sample

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|^(rcfile[[:space:]]*=).*$$|\1"${DATADIR}/dvdwizardrc"|' \
		-e 's|\(seq |(${LOCALBASE}/bin/seq2 |' \
		-e 's|`seq |`${LOCALBASE}/bin/seq2 |' \
		${WRKSRC}/*

do-install:
# script
.for script in ${SCRIPT_FILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${script} ${PREFIX}/bin
.endfor
# examples
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/dvdwizard.conf.sample \
		${EXAMPLESDIR}
# shared data
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/dvdwizardrc \
		${DATADIR}

.include <bsd.port.mk>
