# New ports collection makefile for:    WebGlimpse
# http://glimpse.cs.arizona.edu/webglimpse/
# Version required:                     1.*
# Date created:                         2 Nov 1998
# Whom:                                 ache
#
# $Id: Makefile,v 1.3 1998/11/04 04:16:57 ache Exp $
#

DISTNAME=       webglimpse-1.6.src
PKGNAME=        webglimpse-1.6
CATEGORIES=     www textproc
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/

MAINTAINER=     ache@freebsd.org

RUN_DEPENDS+=   ${PREFIX}/etc/apache/httpd.conf:${PORTSDIR}/www/apache13
RUN_DEPENDS+=   glimpse:${PORTSDIR}/textproc/glimpse

IS_INTERACTIVE=	YES
NO_PACAKGE=	domain name hardcoded
WRKSRC=         ${WRKDIR}/webglimpse-1.6.edu
USE_PERL5=      YES
NO_BUILD=       YES

pre-configure:
.for i in wginstall wginstall.pl
	cd ${WRKSRC}; ${CP} $i $i.tmp; \
		${SED} s=%PERL%=${PERL}= < $i.tmp > $i
.endfor

do-install:
	cd ${WRKSRC}; ./wginstall
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/webglimpse
	cd ${WRKSRC}/docs && ${INSTALL_DATA} * ${PREFIX}/share/doc/webglimpse

.include <bsd.port.mk>
