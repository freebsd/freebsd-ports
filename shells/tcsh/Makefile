# New ports collection makefile for:	tcsh
# Version required:     6.06
# Date created:		22 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.10 1995/06/20 21:20:39 ache Exp $
#

DISTNAME=       tcsh-6.06
CATEGORIES+=	shells
MASTER_SITES=	ftp://tesla.ee.cornell.edu/pub/tcsh/

ALL_TARGET=     all catalogs
INSTALL_TARGET= install install.man

post-install:
	chown bin.bin ${PREFIX}/bin/tcsh
	chown bin.bin ${PREFIX}/man/man1/tcsh.1
	@mkdir -p ${PREFIX}/share/nls/C
	cd ${WRKSRC}; install -c -o bin -g bin -m 444 tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat
	@mkdir -p ${PREFIX}/share/nls/fr_FR.ISO_8859-1
	cd ${WRKSRC}; install -c -o bin -g bin -m 444 tcsh.french.cat ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat
	@mkdir -p ${PREFIX}/share/nls/fr_BE.ISO_8859-1
	ln -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_BE.ISO_8859-1/tcsh.cat
	@mkdir -p ${PREFIX}/share/nls/fr_CA.ISO_8859-1
	ln -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CA.ISO_8859-1/tcsh.cat
	@mkdir -p ${PREFIX}/share/nls/fr_CH.ISO_8859-1
	ln -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CH.ISO_8859-1/tcsh.cat
	@mkdir -p ${PREFIX}/share/nls/de_DE.ISO_8859-1
	cd ${WRKSRC}; install -c -o bin -g bin -m 444 tcsh.german.cat ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat
	@mkdir -p ${PREFIX}/share/nls/de_AT.ISO_8859-1
	ln -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_AT.ISO_8859-1/tcsh.cat
	@mkdir -p ${PREFIX}/share/nls/de_CH.ISO_8859-1
	ln -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_CH.ISO_8859-1/tcsh.cat

MAINTAINER=     ache@FreeBSD.ORG

.include <bsd.port.mk>
