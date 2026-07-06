PORTNAME=	ca_root_nss
DISTVERSION=	3.124
CATEGORIES=	security
MASTER_SITES=	MOZILLA/security/nss/releases/${DISTNAME:tu:C/[-.]/_/g}_RTM/src
DISTNAME=	nss-${DISTVERSION}${NSS_SUFFIX}

MAINTAINER=	ports-secteam@FreeBSD.org
COMMENT=	Root certificate bundle from the Mozilla Project

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 ssl:build
USE_PERL5=	build

EXTRACT_AFTER_ARGS=	--include nss-${DISTVERSION}/nss/COPYING \
			--include nss-${DISTVERSION}/nss/lib/ckfw/builtins/certdata.txt \
			--no-same-owner --no-same-permissions

WRKSRC_SUBDIR=	nss
NO_ARCH=	yes

CERTDIR?=		share/certs
CERTCTL_CMD?=		/usr/sbin/certctl
CERTDATA_TXT_PATH=	lib/ckfw/builtins/certdata.txt
BUNDLE_PROCESSOR=	MAca-bundle.pl

SUB_FILES=	MAca-bundle.pl pkg-deinstall pkg-install pkg-message
SUB_LIST=	CERTCTL_CMD=${CERTCTL_CMD} DISTVERSION=${DISTVERSION}
PLIST_SUB=	CERTDIR=${CERTDIR}

OPTIONS_DEFINE=		ETCSYMLINK
OPTIONS_DEFAULT=	ETCSYMLINK
OPTIONS_EXCLUDE_FreeBSD_15=	ETCSYMLINK
OPTIONS_EXCLUDE_FreeBSD_16=	ETCSYMLINK
OPTIONS_SUB=		yes

ETCSYMLINK_DESC=	Add symlinks to default bundle locations

do-build:
	@${SETENV} PATH=${LOCALBASE}/bin:$${PATH} \
	    ${PERL} ${WRKDIR}/${BUNDLE_PROCESSOR} \
	    < ${WRKSRC}/${CERTDATA_TXT_PATH} > \
	    ${WRKDIR}/ca-root-nss.crt

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CERTDIR}
	${INSTALL_DATA} ${WRKDIR}/ca-root-nss.crt ${STAGEDIR}${PREFIX}/${CERTDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ssl
	${RLN} ../../${CERTDIR}/ca-root-nss.crt ${STAGEDIR}${PREFIX}/etc/ssl/cert.pem.sample

do-install-ETCSYMLINK-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/openssl
	${RLN} ../etc/ssl/cert.pem ${STAGEDIR}${PREFIX}/openssl/cert.pem
	${MKDIR} ${STAGEDIR}/etc/ssl
	${RLN} ../..${PREFIX}/etc/ssl/cert.pem ${STAGEDIR}/etc/ssl/cert.pem

.include <bsd.port.mk>
