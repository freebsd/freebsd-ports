# New ports collection makefile for:    a2ps (letter)
# Version required:     4.10.3
# Date created:         15 July 1998
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $Id: Makefile,v 1.22 1998/11/20 04:15:00 asami Exp $
#

DISTNAME=	a2ps-4.10.3
PKGNAME=	a2ps-${PAPERSIZE}-4.10.3
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/

MAINTAINER=	chuckr@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		a2ps.1 ogonkify.1 card.1 psmandup.1 fixps.1 pdiff.1

PAPERSIZE?=	letter
PAPERSIZECNF=	${PAPERSIZE:S/l/L/:S/a/A/}
STRIP=
CONFIGURE_ARGS=	--with-medium=${PAPERSIZECNF}

.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter && ${PAPERSIZE} != letterdj
.BEGIN:
	@${ECHO}
	@${ECHO} "PAPERSIZE incorrect value: ${PAPERSIZE}."
	@${ECHO}
	@${ECHO} "Must specify PAPERSIZE as one of a4, letter, or letterdj."
	@${ECHO} "letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	strip ${PREFIX}/bin/a2ps
	(cd ${WRKSRC}/doc; ${MAKE} install)

.include <bsd.port.mk>
