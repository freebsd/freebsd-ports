# ex:ts=8
# Ports collection makefile for:  vscan
# Date created:			  Thur Sept 25, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	vscan
PORTVERSION=	3.1.8
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.mcafee.com/pub/antivirus/unix/linux/ \
		http://people.FreeBSD.org/~steve/distfiles/
DISTNAME=	nlxb318e
EXTRACT_SUFX=	.tar

MAINTAINER=	obrien@FreeBSD.org

NO_WRKSUBDIR=	yes
RESTRICTED=	"Commercial software"

LIBDIR=	${PREFIX}/lib/neta
MAN1=	uvscan.1

pre-fetch:
.if defined(PREFIX) && ${PREFIX} != "/usr/local"
	@${ECHO} ""
	@${ECHO} "This software has /usr/local hardcoded into it."
	@${ECHO} "Sorry, but with PREFIX = ${PREFIX}, vscan will not work correctly."
	@${ECHO} ""
	@${FALSE}
.endif

post-extract:
	 cd ${WRKSRC} && tar xzf linux-elf.e.tar.Z

do-build::

# The binary executable file will be left unstripped as stripping the
# file will cause attempt to validate this file to fail.
do-install:
	cd ${WRKSRC}; ./install-vscan

post-install:
	@${CHOWN} ${BINOWN}.${BINGRP} ${PREFIX}/bin/uvscan
	@${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${LIBDIR}
	@${CHOWN} ${MANOWN}.${MANGRP} ${PREFIX}/man/man1/uvscan.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/vscan
	${INSTALL_DATA} ${WRKSRC}/Whatsnew.txt ${PREFIX}/share/doc/vscan
	${INSTALL_DATA} ${WRKSRC}/Readme.1st ${PREFIX}/share/doc/vscan/vscan.LICENCE
.endif
	@${ECHO} ""
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
