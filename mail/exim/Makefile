# New ports collection makefile for:	exim
# Version required:	2.053
# Date created:		23 June 1996
# Whom:			axl@iafrica.com
#
# $Id: Makefile,v 1.20 1998/11/17 04:12:10 asami Exp $
#

DISTNAME=	exim-2.053
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.quite.net/pub/exim/Testing/ \
		http://www.exim.org/ftp/Testing/ \
		ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/Testing/ \
		ftp://ftp.is.co.za/networking/mail/transport/exim/Testing/
DISTFILES=	exim-testing-2.053.tar.gz exim-texinfo-2.00.tar.gz

MAINTAINER=	axl@iafrica.com

USE_PERL5=	YES

do-configure:
	${MKDIR} ${WRKSRC}/Local
	if [ -d ${X11BASE} ] ; then \
		${SED} -e "s#XX_PREFIX_XX#${PREFIX}#" \
		    < ${FILESDIR}/Makefile \
		    > ${WRKSRC}/Local/Makefile ; \
	else \
		${SED} -e "s#XX_PREFIX_XX#${PREFIX}#" \
		    < ${FILESDIR}/Makefile \
		    | ${SED} -e "s/^EXIM_MONITOR/#EXIM_MONITOR/" \
		    > ${WRKSRC}/Local/Makefile ; \
	fi
	${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	${CP} ${FILESDIR}/configure.default ${WRKSRC}/src
	cd ${WRKSRC}/doc && \
	for i in ../../exim-texinfo-2.00/doc/* ; do \
		ln -sf $$i ; \
	done

post-build:
	${INSTALL_SCRIPT} ${FILESDIR}/exim.sh ${WRKSRC}/build-FreeBSD-i386

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${PERL5} ${PKGDIR}/INSTALL \
	    exim-2.053 POST-INSTALL

.include <bsd.port.mk>
