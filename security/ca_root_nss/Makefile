# New ports collection makefile for:    ca-root-nss
# Date created:				Thu Jan 25 13:02:14 CST 2007
# Whom:	      				Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ca_root_nss
PORTVERSION=	${VERSION_NSS}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_MOZILLA} \
		${MASTER_SITES_MODSSL:S/$/:mod_ssl/}
MASTER_SITE_SUBDIR=	security/nss/releases/NSS_${PORTVERSION:S/./_/g}_RTM/src
DISTFILES=	${NSS_FILE} ${MODSSL_FILE}:mod_ssl

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	The root certificate bundle from the Mozilla Project

OPTIONS=	ETCSYMLINK "Add symlink to /etc/ssl/cert.pem" off

USE_PERL5_BUILD=	yes
NO_WRKSUBDIR=	yes

CERTDIR?=	share/certs
PLIST_SUB+=	CERTDIR=${CERTDIR}

# These versions intend to track security/nss and www/apache13-modssl.
VERSION_NSS=	3.12.4
VERSION_APACHE=	1.3.41
VERSION_MODSSL=	2.8.31
MASTER_SITES_MODSSL=	http://www.modssl.org/source/ \
		ftp://ftp.modssl.org/source/ \
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mod_ssl/source,}
MODSSL_FILE=	mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}
NSS_FILE=	nss-${VERSION_NSS}${EXTRACT_SUFX}
CERTDATA_TXT_PATH=	nss-${VERSION_NSS}/mozilla/security/nss/lib/ckfw/builtins/certdata.txt
CA_BUNDLE_PL_PATH=	mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}/pkg.sslcfg/ca-bundle.pl

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ETCSYMLINK)
PLIST_SUB+=	ETCSYMLINK=
CONFLICTS=	ca-roots-[0-9]*
.else
PLIST_SUB+=	ETCSYMLINK="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${TAR} -C ${WRKDIR} -xf ${DISTDIR}/${MODSSL_FILE} \
	    ${CA_BUNDLE_PL_PATH}
	@${TAR} -C ${WRKDIR} -xf ${DISTDIR}/nss-${VERSION_NSS}${EXTRACT_SUFX} \
	    ${CERTDATA_TXT_PATH}
	@${CP} ${WRKDIR}/${CA_BUNDLE_PL_PATH} ${WRKDIR}
	@${CP} ${WRKDIR}/${CERTDATA_TXT_PATH} ${WRKDIR}
	@${RM} -rf ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	    ${WRKDIR}/nss-${VERSION_NSS}

do-build:
	@${PERL} ${WRKDIR}/ca-bundle.pl < ${WRKDIR}/certdata.txt > \
	    ${WRKDIR}/ca-root-nss.crt

do-install:
	${MKDIR} ${PREFIX}/${CERTDIR}
	${INSTALL_DATA} ${WRKDIR}/ca-root-nss.crt ${PREFIX}/${CERTDIR}
.if !defined(WITHOUT_ETCSYMLINK)
	${LN} -s ${PREFIX}/${CERTDIR}/ca-root-nss.crt /etc/ssl/cert.pem
.endif

.include <bsd.port.post.mk>
