# New ports collection makefile for:    cgiwrap
# Date created:         30 July 1998
# Whom:                 Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	cgiwrap
PORTVERSION=	3.6.3
CATEGORIES=	www
MASTER_SITES=	http://www.unixtools.org/cgiwrap/dist/ \
		ftp://ftp.umr.edu/pub/cgi/cgiwrap/ \
		ftp://concert.cert.dfn.de/pub/tools/net/cgiwrap/

MAINTAINER=	bjn@visi.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${HTTPDUSER} ${WITHOUTCHECK} --with-install-dir=${INSTALLDIR} \
		--with-install-group=${BINGRP} --with-cgi-dir=${CGIDIR}

###
# Set this to the directory (relative to each user's home) where CGI
# scripts will be found.  (Another common value is "www/cgi-bin".)
###
CGIDIR=		public_html/cgi-bin

###
# The default security settings are very tight; enable one or more
# of these to loosen them.  Run "configure -help" for information on
# these and other options.
###
#WITHOUTCHECK=	--without-check-owner --without-check-setuid \
#		--without-check-group --without-check-setgid \
#		--without-check-group-writable \
#		--without-check-world-writable

###
# Use these options for Apache:
###
INSTALLDIR=	${PREFIX}/share/apache/cgi-bin
HTTPDUSER=	--with-httpd-user=nobody

pre-install:
	${MKDIR} ${INSTALLDIR}

post-install:
	strip ${INSTALLDIR}/cgiwrap
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cgiwrap
.for file in accesscontrol.html afs.html changes.html comments.html \
		download.html faq.html index.html install.html intro.html \
		maillist.html notes.html pubs.html quickref.html setup.html \
		thanks.html todo.html tricks.html y2k.html
	@${INSTALL_MAN} ${WRKSRC}/htdocs/${file} ${PREFIX}/share/doc/cgiwrap
.endfor
	@${ECHO} "Documentation installed in ${PREFIX}/share/doc/cgiwrap"
.endif

.include <bsd.port.mk>
