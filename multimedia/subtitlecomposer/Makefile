# New ports collection makefile for:	subtitlecomposer
# Date created:		2008-01-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	subtitlecomposer
PORTVERSION=	0.4.0
CATEGORIES=	multimedia
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=subcomposer

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Subtitle editor for KDE

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_AUTOTOOLS=	automake:17:env libtool:15
USE_PERL5_BUILD=yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gstreamer
INSTALLS_ICONS=	yes

OPTIONS=	XINE "Enable Xine backend" off

.include <bsd.port.pre.mk>

.if defined(WITH_XINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
.else
CONFIGURE_ARGS+=--without-xine
.endif

pre-configure:
	@cd ${CONFIGURE_WRKSRC} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS} \
		&& ${PERL} admin/am_edit

.include <bsd.port.post.mk>
