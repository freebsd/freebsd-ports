# New ports collection makefile for:    WebMagick
# http://www.cyberramp.net/~bfriesen/webmagick/
# Version required:                     1.44
# Date created:                         20 May 1998
# Whom:                                 ache
#
# $Id: Makefile,v 1.7 1998/09/15 21:31:54 asami Exp $
#

DISTNAME=       WebMagick-1.44
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
		PERL=${PERL5}

post-install:
		cd ${WRKSRC}; \
		if [ ! -f ${PREFIX}/etc/webmagickrc ] ; then \
		       ${INSTALL_DATA} webmagickrc ${PREFIX}/etc; \
		fi; \
		${INSTALL_DATA} webmagickrc ${PREFIX}/etc/webmagickrc.dist

.include <bsd.port.mk>
