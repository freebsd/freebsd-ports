# Ports collection makefile for:  hmap
# Date created:			  29 Apr 2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hmap
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	http://ujeni.murkyroc.com/hmap/code/current/	\
		http://wwwcsif.cs.ucdavis.edu/~leed/hmap/code/current/
DISTNAME=	${PORTNAME}

MAINTAINER=	onatan@gmail.com
COMMENT=	Web server fingerprinting utility

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

pre-patch:
	${CP} ${WRKSRC}/hmap.py ${WRKSRC}/hmap.py.old
	${TR} -d "\r" < ${WRKSRC}/hmap.py.old > ${WRKSRC}/hmap.py

post-patch:
	${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|' ${WRKSRC}/hmap.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hmap.py ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/hmap/
.	for i in apache.1.3.12.win32 apache.2.0.44.win32 apache.1.3.14.win32 badblue.2.1.win32 apache.1.3.17.win32 dwhttpd.4.1a6.solaris.8 apache.1.3.22.win32 hpws.2.00.1454.solaris.8 apache.1.3.23.rhl.7.3 ibm_http_server.2.0.42.win32 apache.1.3.26.freebsd.4.6.2.r iis.5.0.win32 apache.1.3.26.solaris.8 jigsaw.2.0.5.win32 apache.1.3.27.freebsd.4.7 jigsaw.2.2.0.win32 apache.1.3.27.freebsd.5.0 jigsaw.2.2.2.solaris.8 apache.1.3.27.mac.10.1.5 ncsa.1.3.ultrix.4.4 apache.1.3.27.mac.10.2.4 thttpd.2.23beta1.freebsd.4.6.st apache.1.3.27.rhl.8.0 thttpd.2.23beta1.rhl.7.3 apache.1.3.9.win32 zope.2.6.0.solaris.8 apache.2.0.40.rhl.8.0
		${INSTALL_DATA} ${WRKSRC}/known.servers/$i ${PREFIX}/share/hmap/
.	endfor
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.		for i in README BUGS GPL FAQS HIDING_GUIDE KNOWN_TESTS
			${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.		endfor
.	endif

.include <bsd.port.mk>
