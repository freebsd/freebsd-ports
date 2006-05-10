# New ports collection makefile for:	dvdwizard
# Date created:		Fri Dec  9 03:01:18 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dvdwizard
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	udrecsuite
DISTNAME=	udrec_suite-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Automated creation of DVDs with chapters and menus

RUN_DEPENDS=	\
		toolame:${PORTSDIR}/audio/toolame \
		convert:${PORTSDIR}/graphics/ImageMagick \
		gnuls:${PORTSDIR}/misc/gnuls \
		seq2:${PORTSDIR}/misc/seq2 \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		transcode:${PORTSDIR}/multimedia/transcode \
		y4mscaler:${PORTSDIR}/multimedia/y4mscaler \
		bash:${PORTSDIR}/shells/bash

IGNORE=		has an incomplete dependency list

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MANLANG=	de.ISO8859-1
MAN1=		chaptercheck.1 \
		dvdcpics.1 \
		dvdtguess.1 \
		dvdwizard.1
MAN5=		dvdwizard.conf.5

SCRIPT_FILES=	\
		chaptercheck \
		dvdcpics \
		dvdtguess \
		dvdwizard \
		mk_vmgm \
		mk_vtsm \
		mk_vtsm_audio \
		mpgprobe

PLIST_DIRS=	\
		%%DATADIR%% \
		%%EXAMPLESDIR%%
PLIST_FILES=	\
		${SCRIPT_FILES:S,^,bin/,} \
		bin/dvdwizard_seq \
		%%DATADIR%%/dvdwizardrc \
		%%EXAMPLESDIR%%/dvdwizard.conf.sample

.ifndef(NOPORTDOCS)
PORTDOCS=	README
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|^(rcfile[[:space:]]*=).*$$|\1"${DATADIR}/dvdwizardrc"|' \
		-e 's|`seq[[:space:]]+(.+)`|`dvdwizard_seq \1`|' \
		-e 's|\(seq[[:space:]]+(.+)\)|(dvdwizard_seq \1)|' \
		-e 's|==|=|' \
		-e 's|ls -QS|gnuls -QS|' \
		-e 's|ls -S|gnuls -S|' \
		-e 's|sed[[:space:]]+-i[[:space:]]|sed -i \"\" |' \
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
# emulation
	@${INSTALL_SCRIPT} ${FILESDIR}/dvdwizard_seq \
		${PREFIX}/bin
# man
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/../man/${file} ${MAN1PREFIX}/man/${MANLANG}/man1
.endfor
.for file in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/../man/${file} ${MAN1PREFIX}/man/${MANLANG}/man5
.endfor
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
