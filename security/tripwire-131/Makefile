# Created by: Cy Schubert <Cy.Schubert@uumail.gov.bc.ca>

PORTNAME=	tripwire
PORTVERSION=	1.3.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cc.uoc.gr/system/security/tools/tripwire/ \
		ftp://ftp.uni-potsdam.de/pub/unix/tools/
DISTNAME=	Tripwire-${PORTVERSION}-1
PKGNAMESUFFIX=	-131

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File system security and verification program

# Converted from NO_CDROM
LICENSE=	Tripwire
LICENSE_NAME=	tripwire
LICENSE_TEXT=	Cannot be redistributed for more than the cost of duplication
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

DEPRECATED=	Deprecated, please consider using security/tripwire instead
EXPIRATION_DATE=2022-03-31

USES=		cpe

NO_PACKAGE=	requires local database to be built
# XXX should also work on other 32-bit architectures.
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	cannot determine byte order

WRKSRC=		${WRKDIR}/tw_ASR_1.3.1_src
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

TDATADIR=	${STAGEDIR}/var/local/tcheck
MAKE_ARGS=	BINDIR=${STAGEDIR}${PREFIX}/bin \
		MANPREFIX=${STAGEDIR}${MANPREFIX}
NO_DB_BUILD=	yes

TWCONFIG?=	${FILESDIR}/tw.conf.freebsd2

pre-configure:
	@ ${CP} ${FILESDIR}/conf-freebsd2.h ${WRKSRC}/configs
	@ ${CP} ${TWCONFIG} ${WRKSRC}/configs/tw.conf.freebsd2

post-install:
	@ ${MKDIR} ${TDATADIR}
	@ ${CP} ${TWCONFIG} ${TDATADIR}/tw.config.dist
.ifndef NO_DB_BUILD
	# XXX For reference only
	@ ${ECHO} Creating tripwire database
	@ ${CP} -i ${TWCONFIG} ${TDATADIR}/tw.config
	@ (cd /var/adm/tcheck; tripwire -initialize)
.endif

.include <bsd.port.post.mk>
