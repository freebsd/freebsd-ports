# ex:ts=8
# Ports collection makefile for:  Crack
# Date created:			  12 Jan 1997
# Whom:				  David O'Brien <obrien@FreeBSD.org>
#				  & Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	crack
PORTVERSION=	5.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/security/  \
		ftp://ftp.ox.ac.uk/pub/comp/security/software/crackers/  \
		ftp://ftp.auscert.org.au/pub/coast/mirrors/cert.org/tools/crack/ \
		ftp://ftp.riken.go.jp/pub/net/cert_security_tools/crack/
DISTNAME=	${PORTNAME}${PORTVERSION}	

MAINTAINER=	obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/c50a

pre-configure:
.if !defined(WITH_DES)
	@${MV} -f ${WRKSRC}/src/libdes ${WRKSRC}/src/libdes.notused
	@${MV} -f ${WRKSRC}/src/util/elcid.c ${WRKSRC}/src/util/elcid.c.orig
	@${CP} -p ${WRKSRC}/src/util/elcid.c,bsd ${WRKSRC}/src/util/elcid.c
.endif
	@${ECHO} "XLIB+= -lcrypt" >> ${WRKSRC}/src/util/Makefile

pre-build:
	@(if [ ! -f /usr/share/dict/words ];then \
	    ${ECHO_MSG} "You may want to install the dict distribution into /usr/share/dict" ; \
	    ${ECHO_MSG} "to increase the size of the cracking dictionary." ; \
	fi)

do-build:
	cd ${WRKSRC} ; ./Crack -makeonly
	cd ${WRKSRC} ; ./Crack -makedict
.if !defined(WITH_DES)
	@#(cd ${WRKSRC} ; ./Crack -fgnd -fmt bsd ${FILESDIR}/pw-md5.test)
.endif

do-install:
	@${MKDIR} ${PREFIX}/crack
	@${RM} -f ${WRKSRC}/Run/*
	@cd ${WRKSRC} ; tar cf - . | (cd ${PREFIX}/crack; tar xfBp -)

.include <bsd.port.mk>
