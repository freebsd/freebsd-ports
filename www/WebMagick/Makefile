# New ports collection makefile for:    WebMagick
# http://www.cyberramp.net/~bfriesen/webmagick/
# Version required:                     1.44
# Date created:                         20 May 1998
# Whom:                                 ache
#
# $Id: Makefile,v 1.2 1998/05/19 23:26:46 ache Exp $
#

DISTNAME=       WebMagick-1.44
CATEGORIES=     www
MASTER_SITES=   http://www.cyberramp.net/~bfriesen/webmagick/dist/

MAINTAINER=     ache@freebsd.org

USE_PERL5=      YES
GNU_CONFIGURE=  YES
CONFIGURE_ENV=  webmagick_cv_rootpath=${PREFIX}/www/data \
		webmagick_cv_iconpath=webmagick \
		webmagick_cv_prefixpath="" \
		webmagick_cv_htimage="" \
		webmagick_cv_maptype=ncsa \
		PERL=${PREFIX}/bin/perl

RUN_DEPENDS=    ${PREFIX}/lib/perl5/site_perl/i386-freebsd/auto/Image/Magick/Magick.so:${PORTSDIR}/graphics/p5-PerlMagick

post-install:
		cd ${WRKSRC}; \
		if [ ! -f ${PREFIX}/etc/webmagickrc ] ; then \
		       ${INSTALL_DATA} webmagickrc ${PREFIX}/etc; \
		fi; \
		${INSTALL_DATA} webmagickrc ${PREFIX}/etc/webmagickrc.dist

.include <bsd.port.mk>
