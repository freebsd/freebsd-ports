# New ports collection makefile for:    a2ps (letter)
# Date created:         15 July 1998
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $FreeBSD$
#

PORTNAME=	a2ps
PORTVERSION=	4.13
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.enst.fr/pub/unix/a2ps/
PKGNAMESUFFIX=	-${PAPERSIZE}
DISTFILES=	a2ps-${PORTVERSION}${EXTRACT_SUFX} sheets.map
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	chuckr@FreeBSD.org

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
MAN1=		a2ps.1 ogonkify.1 card.1 psmandup.1 fixps.1 pdiff.1 psset.1 texi2dvi4a2ps.1

PAPERSIZE?=	letter
PAPERSIZECNF=	${PAPERSIZE:S/l/L/:S/a/A/}
STRIP=
CONFIGURE_ARGS=	--with-medium=${PAPERSIZECNF} --sharedstatedir=$(PREFIX)/share --sysconfdir=$(PREFIX)/etc --datadir=$(PREFIX)/share --localstatedir=$(PREFIX)/share

.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter && ${PAPERSIZE} != letterdj
.BEGIN:
	@${ECHO}
	@${ECHO} "PAPERSIZE incorrect value: ${PAPERSIZE}."
	@${ECHO}
	@${ECHO} "Must specify PAPERSIZE as one of a4, letter, or letterdj."
	@${ECHO} "letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.endif

post-extract:
	$(CP) $(DISTDIR)/sheets.map $(WRKSRC)/sheets/sheets.map

post-install:
	strip ${PREFIX}/bin/a2ps
	(cd ${WRKSRC}/doc; ${MAKE} install)
	$(RM) -f $(PREFIX)/lib/liba2ps.la

.include <bsd.port.mk>
