# New ports collection makefile for:    a2ps
# Version required:     4.10.3
# Date created:         15 July 1998
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $Id: Makefile,v 1.18 1998/07/21 11:13:52 asami Exp $
#

DISTNAME=	a2ps-4.10.3
PKGNAME=	a2ps-${PAPERSIZE}-4.10.3
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/

MAINTAINER=	chuckr@FreeBSD.org

MANUAL_PACKAGE_BUILD=  PAPERSIZE has to be set to Letter A4
GNU_CONFIGURE=	yes
MAN1=		a2ps.1 ogonkify.1 card.1 psmandup.1 fixps.1 pdiff.1

PAPERSIZE?=	Letter
STRIP=
CONFIGURE_ARGS=	--with-medium=${PAPERSIZE}

Letter letter:
	${MAKE} PAPERSIZE=Letter

Letterdj letterdj:
	${MAKE} PAPERSIZE=Letterdj

A4 a4:
	${MAKE} PAPERSIZE=A4

pre-configure:
.if ${PAPERSIZE} != A4 && ${PAPERSIZE} != Letter && ${PAPERSIZE} != Letterdj
	@${ECHO}
	@${ECHO} "PAPERSIZE incorrect value: ${PAPERSIZE}."
	@${ECHO}
	@${ECHO} "Must specify PAPERSIZE as one of A4, Letter, or Letterdj, either"
	@${ECHO} "using setenv, or via Makefile targets of the same name.  Note"
	@${ECHO} "that each PAPERSIZE has a leading capital letter, and Letterdj"
	@${ECHO} "allows a slightly larger margins for DeskJets."
	@false
.endif
	${ECHO} ${PAPERSIZE} > ${WRKDIR}/.media

post-install:
	${LDCONFIG} -R ${PREFIX}/lib
	strip ${PREFIX}/bin/a2ps
	(cd ${WRKSRC}/doc; ${MAKE} install)

.include <bsd.port.mk>

.if exists(${WRKDIR}/.media)
PAPERSIZE=
PAPERSIZE!=	${CAT} ${WRKDIR}/.media
.endif
