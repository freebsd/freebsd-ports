# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

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
USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
PLIST_FILES=	bin/youtube-viewer

DEPRECATED=	Development ceased for 2.5 branch, conflict with gtk-youtube-viewer
EXPIRATION_DATE=2014-02-23

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/perl|#!${PERL}|g" ${WRKDIR}/youtube-viewer

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/youtube-viewer ${PREFIX}/bin/

.include <bsd.port.mk>
