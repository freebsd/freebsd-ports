# New ports collection makefile for:    WebGlimpse
# http://glimpse.cs.arizona.edu/webglimpse/
# Version required:                     1.*
# Date created:                         2 Nov 1998
# Whom:                                 ache
#
# $Id: Makefile,v 1.5 1998/11/07 12:39:29 ache Exp $
#

DISTNAME=       webglimpse-1.6.src
PKGNAME=        webglimpse-1.6
CATEGORIES=     www textproc
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/

RUN_DEPENDS+=   /usr/local/etc/apache/httpd.conf:${PORTSDIR}/www/apache13
RUN_DEPENDS+=   glimpse:${PORTSDIR}/textproc/glimpse
WRKSRC=         ${WRKDIR}/webglimpse-1.6.edu

MAINTAINER=     ache@freebsd.org

NO_CDROM=	depends on glimpse
USE_PERL5=      YES
NO_BUILD=       YES

pre-configure:
.for i in wginstall wginstall.pl
	cd ${WRKSRC}; cp $i $i.tmp; \
		sed s=%PERL%=${PERL}= < $i.tmp > $i
.endfor

do-install:
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/www/webglimpse
.if defined(PACKAGE_BUILDING)
	${INSTALL_DATA} ${FILESDIR}/.wgsiteconf ${PREFIX}/www/webglimpse
.endif
	cd ${WRKSRC}; ./wginstall
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/webglimpse
	cd ${WRKSRC}/docs && ${INSTALL_DATA} * ${PREFIX}/share/doc/webglimpse

.include <bsd.port.mk>
