# New ports collection makefile for:	tcsh
# Version required:     6.07.02
# Date created:		22 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.18 1997/11/28 03:35:05 jseger Exp $
#

DISTNAME=       tcsh-6.07
PKGNAME=        tcsh-6.07.02
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.astron.com/pub/tcsh/

MAINTAINER=     ache@FreeBSD.ORG

GNU_CONFIGURE=  yes
WRKSRC=         ${WRKDIR}/${PKGNAME}
ALL_TARGET=     all catalogs
INSTALL_TARGET= install install.man
MAN1=		tcsh.1

post-install:
	chown bin.bin ${PREFIX}/bin/tcsh
	chown bin.bin ${PREFIX}/man/man1/tcsh.1
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.french.cat ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat
	ln -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_BE.ISO_8859-1/tcsh.cat
	ln -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CA.ISO_8859-1/tcsh.cat
	ln -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CH.ISO_8859-1/tcsh.cat
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.german.cat ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat
	ln -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_AT.ISO_8859-1/tcsh.cat
	ln -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_CH.ISO_8859-1/tcsh.cat
	install -d -o ${BINOWN} -g ${BINGRP} -m 755 ${PREFIX}/share/nls/el_GR.ISO_8859-7
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.greek.cat ${PREFIX}/share/nls/el_GR.ISO_8859-7/tcsh.cat

.include <bsd.port.mk>
