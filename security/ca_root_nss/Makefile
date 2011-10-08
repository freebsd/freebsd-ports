# New ports collection makefile for:    ca-root-nss
# Date created:				Thu Jan 25 13:02:14 CST 2007
# Whom:	      				Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ca_root_nss
PORTVERSION=	${VERSION_NSS}
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	security/nss/releases/NSS_${PORTVERSION:S/./_/g}_WITH_CKBI_${CKBI_VER:S/./_/}_RTM/src
DISTNAME=	nss-${VERSION_NSS}${NSS_SUFFIX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The root certificate bundle from the Mozilla Project

OPTIONS=	ETCSYMLINK "Add symlink to /etc/ssl/cert.pem" off

USE_PERL5_BUILD=	yes
NO_WRKSUBDIR=	yes

CERTDIR?=	share/certs
PLIST_SUB+=	CERTDIR=${CERTDIR}

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# !!!  These versions are indented to track security/nss and     !!!
# !!!  www/apache13-modssl.  Please DO NOT submit patches for    !!!
# !!!  new versions until they have been committed there first.  !!!
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
VERSION_NSS=	3.12.11
CKBI_VER=	1.87
VERSION_APACHE=	1.3.41
NSS_SUFFIX=	.with.ckbi.${CKBI_VER}
CERTDATA_TXT_PATH=	nss-${VERSION_NSS}/mozilla/security/nss/lib/ckfw/builtins/certdata.txt
BUNDLE_PROCESSOR=	MAca-bundle.pl

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ETCSYMLINK)
PLIST_SUB+=	ETCSYMLINK=
CONFLICTS=	ca-roots-[0-9]*
.else
PLIST_SUB+=	ETCSYMLINK="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${TAR} -C ${WRKDIR} -xf ${DISTDIR}/nss-${VERSION_NSS}${NSS_SUFFIX}${EXTRACT_SUFX} \
	    ${CERTDATA_TXT_PATH}
	@${CP} ${WRKDIR}/${CERTDATA_TXT_PATH} ${WRKDIR}
	@${CP} ${FILESDIR}/${BUNDLE_PROCESSOR} ${WRKDIR}
	@${RM} -rf ${WRKDIR}/nss-${VERSION_NSS}

post-patch:
	@${PERL} -pi -e 's,%%VERSION_NSS%%,${VERSION_NSS}${NSS_SUFFIX},g;' \
	    ${WRKDIR}/${BUNDLE_PROCESSOR}

do-build:
	@${PERL} ${WRKDIR}/${BUNDLE_PROCESSOR} \
	    < ${WRKDIR}/certdata.txt > \
	    ${WRKDIR}/ca-root-nss.crt

do-install:
	${MKDIR} ${PREFIX}/${CERTDIR}
	${INSTALL_DATA} ${WRKDIR}/ca-root-nss.crt ${PREFIX}/${CERTDIR}
.if !defined(WITHOUT_ETCSYMLINK)
	${LN} -s ${PREFIX}/${CERTDIR}/ca-root-nss.crt /etc/ssl/cert.pem
.endif

.include <bsd.port.post.mk>
