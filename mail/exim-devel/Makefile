# New ports collection makefile for:	exim
# Version required:	2.05
# Date created:		23 June 1996
# Whom:			axl@iafrica.com
#
# $Id: Makefile,v 1.17 1998/10/12 18:48:52 jseger Exp $
#

DISTNAME=	exim-2.05
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-2.05.tar.gz exim-texinfo-2.00.tar.gz

MAINTAINER=	axl@iafrica.com

USE_PERL5=	YES

do-configure:
	${MKDIR} ${WRKSRC}/Local
	if [ ! -d ${X11BASE} ] ; then \
		${SED} -e "s#XX_PREFIX_XX#${PREFIX}#" \
		    < ${FILESDIR}/Makefile.no_eximon \
		    > ${WRKSRC}/Local/Makefile ; \
	else \
		${SED} -e "s#XX_PREFIX_XX#${PREFIX}#" \
		    < ${FILESDIR}/Makefile \
		    > ${WRKSRC}/Local/Makefile ; \
	fi
	${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	${CP} ${FILESDIR}/configure.default ${WRKSRC}/src
	cd ${WRKSRC}/doc && \
	for i in ../../exim-texinfo-2.00/doc/* ; do \
		ln -sf $$i ; \
	done

post-build:
	if [ ! -d ${X11BASE} ] ; then \
		${INSTALL_SCRIPT} ${FILESDIR}/eximon ${FILESDIR}/eximon.bin \
		    ${WRKSRC}/build-FreeBSD-i386 ; \
	fi

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${PERL5} ${PKGDIR}/INSTALL \
	    exim-2.02 POST-INSTALL

.include <bsd.port.mk>
