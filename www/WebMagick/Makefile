# New ports collection makefile for:    WebMagick
# Date created:                         20 May 1998
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	WebMagick
PORTVERSION=	1.46
CATEGORIES=	www graphics
MASTER_SITES=	ftp://ftp.simplesystems.org/pub/WebMagick/

LIB_DEPENDS=	Magick.5:${PORTSDIR}/graphics/ImageMagick

MAINTAINER=	ache@freebsd.org

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	webmagick_cv_rootpath=${PREFIX}/www/data \
		webmagick_cv_iconpath=webmagick \
		webmagick_cv_prefixpath="" \
		webmagick_cv_htimage="" \
		webmagick_cv_maptype=ncsa \
		PERL=${PERL}

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
