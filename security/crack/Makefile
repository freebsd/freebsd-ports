# ex:ts=8
# Ports collection makefile for:  Crack
# Version required:	5.0
# Date created:         12 Jan 1997
# Whom:			David O'Brien <obrien@FreeBSD.org>
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.5 1997/06/09 15:13:41 fenner Exp $
#

DISTNAME=	crack5.0
PKGNAME=	crack-5.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/security/  \
		ftp://ftp.ox.ac.uk/pub/comp/security/software/crackers/  \
		ftp://ftp.auscert.org.au/pub/coast/mirrors/cert.org/tools/crack/ \
		ftp://ftp.riken.go.jp/pub/net/cert_security_tools/crack/

MAINTAINER=     obrien@FreeBSD.org

RESTRICTED=	"contains crypto (libdes)"
WRKSRC=		${WRKDIR}/c50a

pre-configure:
.if !defined(USE_DES)
	@/bin/mv -f ${WRKSRC}/src/libdes ${WRKSRC}/src/libdes.notused
	@/bin/mv -f ${WRKSRC}/src/util/elcid.c ${WRKSRC}/src/util/elcid.c.orig
	@${CP} -p ${WRKSRC}/src/util/elcid.c,bsd ${WRKSRC}/src/util/elcid.c
	@echo "XLIB+= -lcrypt" >> ${WRKSRC}/src/util/Makefile
.endif

pre-build:
	@(if [ ! -f /usr/share/dict/words ];then \
		echo "You may want to install the dict distribution into /usr/share/dict" ; \
		echo "to increase the size of the cracking dictionary." ; \
	fi)

do-build:
	(cd ${WRKSRC} ; ./Crack -makeonly)
	(cd ${WRKSRC} ; ./Crack -makedict)
.if !defined(USE_DES)
	@#(cd ${WRKSRC} ; ./Crack -fgnd -fmt bsd ${FILESDIR}/pw-md5.test)
.endif

do-install:
	@${MKDIR} ${PREFIX}/crack
	@${RM} -f ${WRKSRC}/Run/*
	@(cd ${WRKSRC} ; tar cf - . | (cd ${PREFIX}/crack; tar xfBp -))


.include <bsd.port.mk>
