# New ports collection makefile for:	youtube-viewer
# Date created:		2010-08-17
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	youtube
PORTVERSION=	2.5.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE:S|youtube|trizen|g} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
PKGNAMESUFFIX=	-viewer
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Search and play YouTube videos streaming in MPlayer

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		mplayer:${PORTSDIR}/multimedia/mplayer

USE_PERL5_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/youtube-viewer

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/perl|#!${PERL}|g" ${WRKDIR}/youtube-viewer

do-install:
	@${CHMOD} +x ${WRKDIR}/youtube-viewer
	@${INSTALL_SCRIPT} ${WRKDIR}/youtube-viewer ${PREFIX}/bin/

.include <bsd.port.mk>
