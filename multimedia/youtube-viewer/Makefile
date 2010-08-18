# New ports collection makefile for:	youtube-viewer
# Date created:		2010-08-17
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	youtube
PORTVERSION=	2.1.8
CATEGORIES=	multimedia
MASTER_SITES=	http://trizen.go.ro/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
PKGNAMESUFFIX=	-viewer
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}
EXTRACT_SUFX=	#none

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Search and play YouTube videos streaming in MPlayer

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		mplayer:${PORTSDIR}/multimedia/mplayer

USE_PERL5_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/perl|#!${PERL}|g" ${WRKSRC}/${DISTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/
	@${CHMOD} +x ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
