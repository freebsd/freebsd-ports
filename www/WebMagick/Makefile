# New ports collection makefile for:    WebMagick
# Date created:                         20 May 1998
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	WebMagick
PORTVERSION=	2.03p3
PORTREVISION=	23
PORTEPOCH=	1
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webmagick
DISTNAME=	${PORTNAME}-2.03pre3

MAINTAINER=	ache@freebsd.org
COMMENT=	Image Web Generator - recursively build HTMLs, imagemaps, thumbnails

LIB_DEPENDS=	Magick.10:${PORTSDIR}/graphics/ImageMagick

USE_PERL5=	yes
GNU_CONFIGURE=	yes
INFO=		webmagick
CONFIGURE_ENV=	webmagick_cv_rootpath=${PREFIX}/www/data \
		webmagick_cv_iconpath=webmagick \
		webmagick_cv_prefixpath="" \
		webmagick_cv_htimage="" \
		webmagick_cv_maptype=ncsa \
		PERL=${PERL}

.if !exists(${X11BASE}/bin/xlsfonts)
WITHOUT_X11=	yes
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ENV+=with_x=no
.endif

MAN1=		webmagick.1

pre-install:
	@${MKDIR} ${PREFIX}/www/data

post-install:
	cd ${WRKSRC}; \
	if [ ! -f ${PREFIX}/etc/webmagickrc ] ; then \
		${INSTALL_DATA} webmagickrc ${PREFIX}/etc; \
	fi; \
	${INSTALL_DATA} webmagickrc ${PREFIX}/etc/webmagickrc.dist

.include <bsd.port.mk>
