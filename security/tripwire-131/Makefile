# Created by: Cy Schubert <Cy.Schubert@uumail.gov.bc.ca>
# $FreeBSD$

PORTNAME=	tripwire
PORTVERSION=	1.3.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cc.uoc.gr/system/security/tools/tripwire/ \
		ftp://ftp.uni-potsdam.de/pub/unix/tools/
DISTNAME=	Tripwire-${PORTVERSION}-1
PKGNAMESUFFIX=	-131

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File system security and verification program

BROKEN=		Does not build
MAN5=		tw.config.5
MAN8=		siggen.8 tripwire.8
NO_CDROM=	Cannot be redistributed for more than the cost of duplication
NO_PACKAGE=	requires local database to be built
WRKSRC=		${WRKDIR}/tw_ASR_1.3.1_src
MAKE_JOBS_UNSAFE=	yes

TWCONFIG?=	${FILESDIR}/tw.conf.freebsd2

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
