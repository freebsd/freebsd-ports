# New ports collection makefile for:    WebMagick
# Date created:                         20 May 1998
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	WebMagick
PORTVERSION=	2.03p3
PORTREVISION=	46
PORTEPOCH=	1
CATEGORIES=	www graphics
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}-beta/2.03pre3
DISTNAME=	${PORTNAME}-2.03pre3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Web Generator - recursively build HTMLs, imagemaps, thumbnails

LIB_DEPENDS=	MagickWand.5:${PORTSDIR}/graphics/ImageMagick

USE_PERL5=	yes
GNU_CONFIGURE=	yes
INFO=		webmagick
CONFIGURE_ENV=	webmagick_cv_rootpath=${PREFIX}/www/data \
		webmagick_cv_iconpath=webmagick \
		webmagick_cv_prefixpath="" \
		webmagick_cv_htimage="" \
		webmagick_cv_maptype=ncsa \
		PERL=${PERL}

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/bin/xlsfonts)
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

.include <bsd.port.post.mk>
