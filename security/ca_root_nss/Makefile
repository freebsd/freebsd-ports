# $FreeBSD$

PORTNAME=	ca_root_nss
PORTVERSION=	${VERSION_NSS}
CATEGORIES=	security
MASTER_SITES=	MOZILLA/security/nss/releases/${DISTNAME:tu:C/[-.]/_/g}_RTM/src
DISTNAME=	nss-${VERSION_NSS}${NSS_SUFFIX}

MAINTAINER=	ports-secteam@FreeBSD.org
COMMENT=	Root certificate bundle from the Mozilla Project

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 ssl:build
USE_PERL5=	build

NO_ARCH=	yes
WRKSRC_SUBDIR=	nss

OPTIONS_DEFINE=		ETCSYMLINK
OPTIONS_DEFAULT=	ETCSYMLINK

OPTIONS_SUB=		yes

ETCSYMLINK_DESC=	Add symlink to /etc/ssl/cert.pem
ETCSYMLINK_CONFLICTS_INSTALL=	ca-roots-[0-9]*

CERTDIR?=	share/certs
PLIST_SUB+=	CERTDIR=${CERTDIR}

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# !!!  These versions are intended to track security/nss.        !!!
# !!!  Please DO NOT submit patches for new version until it has !!!
# !!!  been committed there first.                               !!!
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
VERSION_NSS=	3.55
#NSS_SUFFIX=	-with-ckbi-1.98
CERTDATA_TXT_PATH=	lib/ckfw/builtins/certdata.txt
BUNDLE_PROCESSOR=	MAca-bundle.pl

SUB_FILES=	MAca-bundle.pl pkg-message
SUB_LIST=	VERSION_NSS=${VERSION_NSS}

do-build:	apply-slist
	@${SETENV} PATH=${LOCALBASE}/bin:$${PATH} \
		${PERL} ${WRKDIR}/${BUNDLE_PROCESSOR} \
	    < ${WRKSRC}/${CERTDATA_TXT_PATH} > \
	    ${WRKDIR}/ca-root-nss.crt

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CERTDIR}
	${INSTALL_DATA} ${WRKDIR}/ca-root-nss.crt ${STAGEDIR}${PREFIX}/${CERTDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ssl
	${LN} -sf ../../${CERTDIR}/ca-root-nss.crt ${STAGEDIR}${PREFIX}/etc/ssl/cert.pem.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/openssl
	${LN} -sf ../${CERTDIR}/ca-root-nss.crt ${STAGEDIR}${PREFIX}/openssl/cert.pem.sample

do-install-ETCSYMLINK-on:
	${MKDIR} ${STAGEDIR}/etc/ssl
	${LN} -sf ../..${PREFIX}/${CERTDIR}/ca-root-nss.crt ${STAGEDIR}/etc/ssl/cert.pem

.include <bsd.port.mk>
