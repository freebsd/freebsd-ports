# New ports collection makefile for:    WebMagick
# http://www.cyberramp.net/~bfriesen/webmagick/
# Version required:                     1.4*
# Date created:                         20 May 1998
# Whom:                                 ache
#
# $Id: Makefile,v 1.10 1998/12/02 06:20:35 asami Exp $
#

DISTNAME=       WebMagick-1.45
CATEGORIES=     www
MASTER_SITES=   http://www.cyberramp.net/~bfriesen/webmagick/dist/

LIB_DEPENDS=    Magick.4:${PORTSDIR}/graphics/ImageMagick

MAINTAINER=     ache@freebsd.org

USE_PERL5=      YES
GNU_CONFIGURE=  YES
CONFIGURE_ENV=  webmagick_cv_rootpath=${PREFIX}/www/data \
		webmagick_cv_iconpath=webmagick \
		webmagick_cv_prefixpath="" \
		webmagick_cv_htimage="" \
		webmagick_cv_maptype=ncsa \
		PERL=${PERL}

MAN1=           webmagick.1

pre-install:
		@${MKDIR} ${PREFIX}/www/data

post-install:
		cd ${WRKSRC}; \
		if [ ! -f ${PREFIX}/etc/webmagickrc ] ; then \
		       ${INSTALL_DATA} webmagickrc ${PREFIX}/etc; \
		fi; \
		${INSTALL_DATA} webmagickrc ${PREFIX}/etc/webmagickrc.dist

.include <bsd.port.mk>
