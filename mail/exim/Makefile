# New ports collection makefile for:	exim
# Version required:	3.02
# Date created:		23 June 1996
# Whom:			markm@FreeBSD.ORG
#
# $Id: Makefile,v 1.33 1999/06/17 08:53:10 sheldonh Exp $
#

DISTNAME=	exim-3.02
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/ \
		ftp://ftp.quite.net/pub/exim/ \
		http://www.exim.org/ftp/ \
		ftp://ftp.is.co.za/networking/mail/transport/exim/
DISTFILES=	exim-3.02.tar.gz exim-texinfo-3.00.tar.gz

MAINTAINER=	sheldonh@FreeBSD.org

# If USE_XLIB is defined, the eximon monitor, which requires X, will be
# built.
USE_XLIB=	YES

USE_PERL5=	YES

MAKE_ENV+=	OSTYPE=${OPSYS} ARCHTYPE=${MACHINE_ARCH}

do-configure:
	${MKDIR} ${WRKSRC}/Local
.if defined(USE_XLIB) && ${USE_XLIB} == YES
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
	for i in ../../exim-texinfo-3.00/doc/* ; do \
		ln -sf $$i ; \
	done

post-build:
	${INSTALL_SCRIPT} ${FILESDIR}/exim.sh \
		${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}
	${TOUCH} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon.bin
	${TOUCH} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon

.include <bsd.port.mk>
