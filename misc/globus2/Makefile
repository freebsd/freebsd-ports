# Ports collection makefile for:	globus2
# Date created:				January 16, 2004
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	globus
PORTVERSION=	${GLOBUS_VER}.3
PORTREVISION=	1
CATEGORIES=	misc net parallel
MASTER_SITES=	ftp://ftp.globus.org/pub/gt2/${GLOBUS_VER}/${PORTVERSION}/%SUBDIR%/:bundles,updates
MASTER_SITE_SUBDIR=	bundles/src/:bundles updates/src/:updates
DIST_SUBDIR=	globus
EXTRACT_ONLY=

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	The Globus Toolkit version ${GLOBUS_VER}

NOMANCOMPRESS=	yes
MANPREFIX=	${GLOBUS_LOCATION}

.include "${.CURDIR}/Makefile.man"

BUNDLES_DM+=	data-management-client
BUNDLES_DM+=	data-management-sdk
BUNDLES_DM+=	data-management-server
BUNDLES_IS+=	information-services-client
BUNDLES_IS+=	information-services-sdk
BUNDLES_IS+=	information-services-server
BUNDLES_RM+=	resource-management-client
BUNDLES_RM+=	resource-management-sdk
BUNDLES_RM+=	resource-management-server
BUNDLE_FILES_DM=	${BUNDLES_DM:S/^/globus-/:S/$/-${PORTVERSION}-src_bundle.tar.gz/}
BUNDLE_FILES_IS=	${BUNDLES_IS:S/^/globus-/:S/$/-${PORTVERSION}-src_bundle.tar.gz/}
BUNDLE_FILES_RM=	${BUNDLES_RM:S/^/globus-/:S/$/-${PORTVERSION}-src_bundle.tar.gz/}
BUNDLE_FILES=	${BUNDLE_FILES_DM} ${BUNDLE_FILES_IS} ${BUNDLE_FILES_RM}
DISTFILES+=	${BUNDLE_FILES:S/$/:bundles/}

UPDATES_NOTHR+=	common-3.17
UPDATES_THR+=	common-3.17
UPDATES_NOTHR+=	ftp_client-1.10
UPDATES_NOTHR+=	ftp_control-1.10
UPDATES_NOTHR+=	gridftp_server-1.12
UPDATES_THR+=	ldapmodules-0.14
UPDATES_THR+=	openldap-2.0.22
UPDATES_NOTHR+=	openssl-0.20
UPDATES_THR+=	openssl-0.20
UPDATE_FILES_NOTHR=	${UPDATES_NOTHR:S/^/globus_/:S/$/.tar.gz/}
UPDATE_FILES_THR=	${UPDATES_THR:S/^/globus_/:S/$/.tar.gz/}
UPDATE_FILES=	${UPDATE_FILES_NOTHR} ${UPDATE_FILES_THR}
DISTFILES+=	${UPDATE_FILES:S/$/:updates/}

GLOBUS_VER=	2.4
GPT_LOCATION?=	${LOCALBASE}
GPT_BUILD?=	${GPT_LOCATION}/sbin/gpt-build
GLOBUS_BASE?=	globus
GLOBUS_LOCATION=${PREFIX}/${GLOBUS_BASE}

BUILD_DEPENDS+=	${GPT_BUILD}:${PORTSDIR}/misc/gpt
RUN_DEPENDS+=	${GPT_BUILD}:${PORTSDIR}/misc/gpt

# Don't extract anything
NO_BUILD=	yes

.include <bsd.port.pre.mk>

# XXX: We should build 64-bit flavors on 64-bit platforms, but the
# 32-bit flavors build there and the 64-bit ones don't.  This probalby
# needs to be fixed in the globus repo.
#.if ${ARCH} == i386 || ${ARCH} == ppc
BASE_FLAVOR=	gcc32dbg
#.else
#BASE_FLAVOR=	gcc64dbg
#.endif

.if ${ARCH} == amd64
IGNORE=		Autoconf breakage due to x86_64 vs amd64
.endif
.if ${OSVERSION} < 500000
BROKEN=		Does not build on 4.x
.endif

PLIST_SUB+=	BASE_FLAVOR=${BASE_FLAVOR}
PLIST_SUB+=	GLOBUS_BASE=${GLOBUS_BASE}/

do-install:
.for BUNDLE in ${BUNDLE_FILES_DM}
	GPT_LOCATION=${GPT_LOCATION} GLOBUS_LOCATION=${GLOBUS_LOCATION} \
	    ${GPT_BUILD} -builddir=${WRKSRC}/BUILD \
	    ${DISTDIR}/${DIST_SUBDIR}/${BUNDLE} ${BASE_FLAVOR}
.endfor
.for BUNDLE in ${BUNDLE_FILES_RM}
	GPT_LOCATION=${GPT_LOCATION} GLOBUS_LOCATION=${GLOBUS_LOCATION} \
	    ${GPT_BUILD} -builddir=${WRKSRC}/BUILD \
	    ${DISTDIR}/${DIST_SUBDIR}/${BUNDLE} ${BASE_FLAVOR}
.endfor
.for BUNDLE in ${BUNDLE_FILES_IS}
	GPT_LOCATION=${GPT_LOCATION} GLOBUS_LOCATION=${GLOBUS_LOCATION} \
	    ${GPT_BUILD} -builddir=${WRKSRC}/BUILD \
	    ${DISTDIR}/${DIST_SUBDIR}/${BUNDLE} ${BASE_FLAVOR}pthr
.endfor
.for UPDATE in ${UPDATES_NOTHR}
	GPT_LOCATION=${GPT_LOCATION} GLOBUS_LOCATION=${GLOBUS_LOCATION} \
	    ${GPT_BUILD} -update -builddir=${WRKSRC}/BUILD \
	    ${DISTDIR}/${DIST_SUBDIR}/${UPDATE:S/^/globus_/:S/$/.tar.gz/} \
	    ${BASE_FLAVOR}
	${RM} -rf ${GLOBUS_LOCATION}/etc/gpt/packages/`echo ${UPDATE:S/^/globus_/} | ${SED} -e 's/-[0-9.]*//'`/bak
.endfor
.for UPDATE in ${UPDATES_THR}
	GPT_LOCATION=${GPT_LOCATION} GLOBUS_LOCATION=${GLOBUS_LOCATION} \
	    ${GPT_BUILD} -update -builddir=${WRKSRC}/BUILD \
	    ${DISTDIR}/${DIST_SUBDIR}/${UPDATE:S/^/globus_/:S/$/.tar.gz/} \
	    ${BASE_FLAVOR}pthr
	${RM} -rf ${GLOBUS_LOCATION}/etc/gpt/packages/`echo ${UPDATE:S/^/globus_/} | ${SED} -e 's/-[0-9.]*//'`/bak
.endfor

.include <bsd.port.post.mk>
