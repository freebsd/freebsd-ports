# New ports collection makefile for:    a2ps (letter)
# Date created:         15 July 1998
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $FreeBSD$
#

PORTNAME=	a2ps
PORTVERSION=	4.13b
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.enst.fr/pub/unix/a2ps/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${PAPERSIZE}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Formats an ascii file for printing on a postscript printer

USE_PERL5=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
MAN1=		a2ps.1 ogonkify.1 card.1 psmandup.1 fixps.1 pdiff.1 psset.1 texi2dvi4a2ps.1
INFO=		a2ps ogonkify regex
WRKSRC=		${WRKDIR}/${PORTNAME}-4.13

PAPERSIZE?=	letter
PAPERSIZECNF=	${PAPERSIZE:S/l/L/:S/a/A/}
STRIP=
CONFIGURE_ARGS=	--with-medium=${PAPERSIZECNF} --sharedstatedir=${PREFIX}/share --sysconfdir=${PREFIX}/etc --datadir=${PREFIX}/share --localstatedir=${PREFIX}/share

.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter && ${PAPERSIZE} != letterdj
.BEGIN:
	@${ECHO_CMD}
	@${ECHO_CMD} "PAPERSIZE incorrect value: ${PAPERSIZE}."
	@${ECHO_CMD}
	@${ECHO_CMD} "Must specify PAPERSIZE as one of a4, letter, or letterdj."
	@${ECHO_CMD} "letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.endif

.if ${PAPERSIZE} == a4
CONFLICTS?=	a2ps-letter-4.* a2ps-letterdj-4.*
.else
.if ${PAPERSIZE} == letter
CONFLICTS?=	a2ps-a4-4.* a2ps-letterdj-4.*
.else
CONFLICTS?=	a2ps-a4-4.* a2ps-letter-4.*
.endif
.endif

.if defined(WITH_EMACS)
PLIST_SUB+=	WITHEMACS=""
.else
PLIST_SUB+=	WITHEMACS="@comment "
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/a2ps
	(cd ${WRKSRC}/doc; ${MAKE} install)
	install-info ${PREFIX}/info/a2ps.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/ogonkify.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/regex.info ${PREFIX}/info/dir
	${RM} -f ${PREFIX}/lib/liba2ps.la

.include <bsd.port.mk>
