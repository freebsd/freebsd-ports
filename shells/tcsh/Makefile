# New ports collection makefile for:	tcsh
# Date created:		22 August 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tcsh
PORTVERSION=	6.11.00
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400021
DISTFILES=	# empty
NO_BUILD=	yes
PLIST=		${PKGDIR}/pkg-plist.nobuild
.else
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
ALL_TARGET=	all catalogs
MAN1=		tcsh.1
BINOWN=		bin
BINGRP=		bin
.endif

.if ${OSVERSION} >= 400021
pre-everything::
	@${ECHO_MSG} "This port is just for making symlink from /bin/tcsh"
	@${ECHO_MSG} "to ${PREFIX}/bin/tcsh and updating /etc/shells."

do-patch:

do-install:
	${LN} -sf /bin/tcsh ${PREFIX}/bin/tcsh
.else
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcsh ${PREFIX}/bin/tcsh
	${INSTALL_MAN} ${WRKSRC}/tcsh.man ${MANPREFIX}/man/man1/tcsh.1
	${INSTALL_DATA} ${WRKSRC}/tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.german.cat ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_AT.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_CH.ISO_8859-1/tcsh.cat
	@${MKDIR} ${PREFIX}/share/nls/el_GR.ISO_8859-7
	${INSTALL_DATA} ${WRKSRC}/tcsh.greek.cat ${PREFIX}/share/nls/el_GR.ISO_8859-7/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.spanish.cat ${PREFIX}/share/nls/es_ES.ISO_8859-1/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.finnish.cat ${PREFIX}/share/nls/fi_FI.ISO_8859-1/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.french.cat ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_BE.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CA.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CH.ISO_8859-1/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.italian.cat ${PREFIX}/share/nls/it_IT.ISO_8859-1/tcsh.cat
.endif

post-install:
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/tcsh /etc/shells.bak; \
	  ${ECHO} ${PREFIX}/bin/tcsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.post.mk>
