# New ports collection makefile for:	tcsh
# Version required:	6.09
# Date created:		22 August 1994
# Whom:			jkh
#
# $FreeBSD$
#

DISTNAME=       tcsh-6.09
PKGNAME=        tcsh-6.09.00
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.astron.com/pub/tcsh/

MAINTAINER=     ache@FreeBSD.org

Y2K=		ftp://ftp.astron.com/pub/tcsh/Y2K

GNU_CONFIGURE=  yes
WRKSRC=         ${WRKDIR}/${PKGNAME}
ALL_TARGET=     all catalogs
INSTALL_TARGET= install install.man
MAN1=		tcsh.1

post-install:
	${CHOWN} bin.bin ${PREFIX}/bin/tcsh
	${CHOWN} bin.bin ${PREFIX}/man/man1/tcsh.1
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.french.cat ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_BE.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CA.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CH.ISO_8859-1/tcsh.cat
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.german.cat ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_AT.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_CH.ISO_8859-1/tcsh.cat
	install -d -o ${BINOWN} -g ${BINGRP} -m 755 ${PREFIX}/share/nls/el_GR.ISO_8859-7
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.greek.cat ${PREFIX}/share/nls/el_GR.ISO_8859-7/tcsh.cat
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/tcsh /etc/shells.bak; \
	  ${ECHO} ${PREFIX}/bin/tcsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
