# New ports collection makefile for:	tripwire 1.3.1
# Date created:		Fri Mar 19 18:29:18 1999
# Whom:			Cy Schubert <Cy.Schubert@uumail.gov.bc.ca>
#
# $FreeBSD$
#

PORTNAME=	tripwire
PORTVERSION=	1.3.1
CATEGORIES=	security
DISTNAME=	Tripwire-${PORTVERSION}-1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File system security and verification program

LATEST_LINK=	tripwire-131
MAN5=		tw.config.5
MAN8=		siggen.8 tripwire.8
NO_CDROM=	"cannot be redistributed for more than the cost of duplication"
NO_PACKAGE=	"requires local database to be built"
WRKSRC=		${WRKDIR}/tw_ASR_1.3.1_src

TWCONFIG?=	${FILESDIR}/tw.conf.freebsd2

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='Please read http://www.tripwiresecurity.com/ for details of how to obtain the Tripwire source.  Put the file ${DISTNAME}${EXTRACT_SUFX} into the directory ${DISTDIR} and run make again.'
.endif

pre-configure:
	@ ${CP} ${FILESDIR}/conf-freebsd2.h ${WRKSRC}/configs
	@ ${CP} ${TWCONFIG} ${WRKSRC}/configs/tw.conf.freebsd2

post-install:
	@ ${MKDIR} /var/adm/tcheck
	@ ${CP} ${TWCONFIG} /var/adm/tcheck/tw.config
.ifndef NO_DB_BUILD
	@ ${ECHO} Creating tripwire database
	@ (cd /var/adm/tcheck; tripwire -initialize)
.endif

.include <bsd.port.post.mk>
