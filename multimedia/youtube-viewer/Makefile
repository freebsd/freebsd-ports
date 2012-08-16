# New ports collection makefile for:	youtube-viewer
# Date created:		2010-08-17
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	youtube
PORTVERSION=	2.5.9
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
PKGNAMESUFFIX=	-viewer
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Search and play YouTube videos streaming in MPlayer

LICENSE=	GPLv3

RUN_DEPENDS=	p5-XML-Fast>=0:${PORTSDIR}/net/p5-XML-Fast \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor \
		mplayer:${PORTSDIR}/multimedia/mplayer

PROJECTHOST=	trizen
USE_PERL5_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/youtube-viewer

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/perl|#!${PERL}|g" ${WRKDIR}/youtube-viewer

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/youtube-viewer ${PREFIX}/bin/

.include <bsd.port.mk>
