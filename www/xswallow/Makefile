# New ports collection makefile for:	xswallow
# Date created:		1 May 2000
# Whom:			Conrad Sabatier <conrads@home.com>
#
# $FreeBSD$
#

PORTNAME=	xswallow
PORTVERSION=	1.0.18
CATEGORIES=	www
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/X/
DISTNAME=	XswallowSource-${PORTVERSION}

MAINTAINER=	conrads@home.com

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/xswallow/xswallow

PORTOBJFORMAT=	aout

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} >= 500040 )
IGNORE=		"a.out binaries cannot be built on 5.0"
.endif

#can't use ${INSTALL_PROGRAM} with aout binaries, do strip separately

STRIP=		/usr/libexec/aout/strip

#Makefile in distribution doesn't link properly

do-build:
		cd ${WRKSRC} && ${CC} ${CFLAGS} -o xswallow.so -aout \
			-shared -nostdlib -DXP_UNIX -I../include \
			-I${X11BASE}/include -L/usr/lib/compat/aout -lgcc \
			UnixShell.c stubs.c

do-install:
		${MKDIR} ${PREFIX}/lib/netscape/plugins
		${MKDIR} ${PREFIX}/share/examples/xswallow

		${INSTALL} ${COPY} ${WRKSRC}/xswallow.so \
			${PREFIX}/lib/netscape/plugins
		${STRIP} ${PREFIX}/lib/netscape/plugins/xswallow.so

		${INSTALL_DATA} ${WRKSRC}/xswallow.conf \
			${PREFIX}/share/examples/xswallow

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xswallow
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/xswallow
.endif

post-install:
	@echo
	@echo XSwallow plugin was installed in ${PREFIX}/lib/netscape/plugins.
	@echo If your Netscape installation uses a different location,
	@echo then move xswallow.so from the above location to there.
	@echo
	@echo You should copy the sample configuration file
	@echo ${PREFIX}/share/examples/xswallow/xswallow.conf
	@echo to your ~/.netscape directory.
	@echo
	@echo More documentation and some pages for testing your
	@echo configuration are available at
	@echo
	@echo WWW: http://skynet.csn.ul.ie/~caolan/docs/XSwallow.html
	@echo

.include <bsd.port.post.mk>
