# New ports collection makefile for:    cgiwrap
# Date created:         30 July 1998
# Whom:                 Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	cgiwrap
PORTVERSION=	3.7.1
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jre@vineyard.net

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httpd-user=${HTTPDUSER} \
		--with-install-dir=${MAINCGIDIR} \
		--with-install-group=${BINGRP} \
		--with-cgi-dir=${CGIDIR} \
		--with-allow-file=${ALLOWFILE} \
		--with-deny-file=${DENYFILE} \
		${WITHOUTCHECK}

###
# Set this to the directory (relative to each user's home) where CGI
# scripts will be found.  (Another common value is "www/cgi-bin".)
###
CGIDIR?=		public_html/cgi-bin
###
# The default security settings are very tight; enable one or more
# of these to loosen them.  Run "configure -help" for information on
# these and other options.
###
#WITHOUTCHECK?=	--without-check-owner --without-check-setuid \
#		--without-check-group --without-check-setgid \
#		--without-check-group-writable \
#		--without-check-world-writable
###
# Use these options for Apache:
###
MAINCGIDIR?=	${PREFIX}/www/cgi-bin
HTTPDUSER?=	www
###
# The allow and deny files control access to cgiwrap.
###
ALLOWFILE?=	${PREFIX}/etc/${PORTNAME}.allow
DENYFILE?=	${PREFIX}/etc/${PORTNAME}.deny

pre-install:
	@${MKDIR} ${MAINCGIDIR}

post-install:
	${STRIP_CMD} ${MAINCGIDIR}/cgiwrap
	${RM} ${MAINCGIDIR}/cgiwrapd ${MAINCGIDIR}/nph-cgiwrapd
	${CP} ${MAINCGIDIR}/cgiwrap ${MAINCGIDIR}/cgiwrapd
	${LN} ${MAINCGIDIR}/cgiwrapd ${MAINCGIDIR}/nph-cgiwrapd
	${CHMOD} 644 ${MAINCGIDIR}/cgiwrapd
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in accesscontrol.html afs.html changes.html comments.html \
		download.html faq.html index.html install.html intro.html \
		maillist.html notes.html pubs.html quickref.html setup.html \
		thanks.html todo.html tricks.html y2k.html
	@${INSTALL_DATA} ${WRKSRC}/htdocs/${file} ${DOCSDIR}
.endfor
	@${ECHO} "Documentation installed in ${DOCSDIR}"
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
