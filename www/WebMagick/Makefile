# New ports collection makefile for:    WebMagick
# Date created:                         20 May 1998
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	WebMagick
PORTVERSION=    2.0p4
CATEGORIES=	www graphics
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=     webmagick
DISTNAME=       ${PORTNAME}-2.0pre4

MAINTAINER=	ache@freebsd.org

LIB_DEPENDS=	Magick.5:${PORTSDIR}/graphics/ImageMagick

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
	cd ${WRKSRC}/icons; \
		${INSTALL_DATA} blue_help.gif ${PREFIX}/www/data/webmagick/blue_c.gif

.include <bsd.port.mk>
