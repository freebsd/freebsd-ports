# New ports collection makefile for:		kwebwatch
# Date created:         11 June 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	kwebwatch
PORTVERSION=	0.9.6
PORTEPOCH=	1
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_KDELIBS_VER=	2
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
CONFIGURE_ENV=	KDEDIR="${LOCALBASE}" CFLAGS="${CFLAGS} -g" \
		CXXFLAGS="${CXXFLAGS} -g"

MAN1=	kwebwatch.1

post-patch:
	@${PERL} -pi -e "s!-O2!!;s!-pthread!${PTHREAD_LIBS} \
		${PTHREAD_CFLAGS}!" ${WRKSRC}/configure
	@${PERL} -pi -e 's!/usr/bin/perl!${PERL}!' \
		${WRKSRC}/kwebwatch/kwebdiff
	@${PERL} -pi -e 's!(#define.+$$)!\1\n#include <sys/types.h>!' \
		${WRKSRC}/libwebwatch/url.h
	@${PERL} -pi.orig -e 's!^(#include "util.h".*)$$!\1\n#include <time.h>!' ${WRKSRC}/libwebwatch/util.cpp
	@${PERL} -pi.orig -e 's!^(#include <stdlib.h>.*)$$!\1\n#include <sys/types.h>!' ${WRKSRC}/libwebwatch/web.cpp
	@${PERL} -pi.orig -e \
		's!(ln -s )\$$\(kde_htmldir\)(/en/common)/( \$$\(kde_htmldir\)/en/kwebwatch/)!\1${LOCALBASE}/share/doc/HTML/\2\3!' \
		${WRKSRC}/kwebwatch/Makefile.in
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${PERL} -pi -e 's!kdiff!kwebdiff!g'

.include <bsd.port.mk>
