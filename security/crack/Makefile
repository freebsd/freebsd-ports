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
MASTER_SITES=	ftp://ftp.cerias.purdue.edu/pub/tools/unix/pwdutils/crack/ \
		ftp://ftp.cert.dfn.de/pub/tools/password/Crack/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	Crackers/crack
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "Sensible" Unix Password Cracker

WRKSRC=		${WRKDIR}/c50a

pre-configure:
.if !defined(WITH_DES)
	@${MV} -f ${WRKSRC}/src/libdes ${WRKSRC}/src/libdes.notused
	@${MV} -f ${WRKSRC}/src/util/elcid.c ${WRKSRC}/src/util/elcid.c.orig
	@${CP} -p ${WRKSRC}/src/util/elcid.c,bsd ${WRKSRC}/src/util/elcid.c
.endif
	@${ECHO_CMD} "XLIB+= -lcrypt" >> ${WRKSRC}/src/util/Makefile

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
	@cd ${WRKSRC} ; ${TAR} cf - . | (cd ${PREFIX}/crack; ${TAR} xfBp -)

.include <bsd.port.mk>
