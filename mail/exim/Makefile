# New ports collection makefile for:	exim
# Version required:	2.054
# Date created:		23 June 1996
# Whom:			markm@FreeBSD.ORG
#
# $Id: Makefile,v 1.23 1998/11/29 12:21:58 asami Exp $
#

DISTNAME=	exim-2.054
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.quite.net/pub/exim/Testing/ \
		ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/Testing/ \
		http://www.exim.org/ftp/Testing/ \
		ftp://ftp.is.co.za/networking/mail/transport/exim/Testing/
DISTFILES=	exim-testing-2.054.tar.gz exim-texinfo-2.00.tar.gz

MAINTAINER=	axl@iafrica.com

# If USE_XLIB is defined, the eximon monitor, which requires X, will be
# built.
USE_XLIB=	YES

USE_PERL5=	YES

do-configure:
	${MKDIR} ${WRKSRC}/Local
.if defined(USE_XLIB)
	${SED} -e "s#XX_PREFIX_XX#${PREFIX}#" \
	    < ${FILESDIR}/Makefile \
	    > ${WRKSRC}/Local/Makefile
.else
	${SED} -e "s#XX_PREFIX_XX#${PREFIX}#" \
	    -e "s/^EXIM_MONITOR/#EXIM_MONITOR/" \
	    < ${FILESDIR}/Makefile \
	    > ${WRKSRC}/Local/Makefile
.endif

	${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	${SED} -e "s#XX_BINOWN_XX#${BINOWN}#" \
	    < ${FILESDIR}/configure.default > ${WRKSRC}/src/configure.default
	cd ${WRKSRC}/doc && \
	for i in ../../exim-texinfo-2.00/doc/* ; do \
		ln -sf $$i ; \
	done

post-build:
	${INSTALL_SCRIPT} ${FILESDIR}/exim.sh ${WRKSRC}/build-FreeBSD-i386
	${TOUCH} ${WRKSRC}/build-FreeBSD-i386/eximon.bin
	${TOUCH} ${WRKSRC}/build-FreeBSD-i386/eximon

pre-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
