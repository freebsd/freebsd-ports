# $FreeBSD$

PORTNAME=	ca_root_nss
PORTVERSION=	${VERSION_NSS}
CATEGORIES=	security
MASTER_SITES=	MOZILLA/security/nss/releases/${DISTNAME:U:C/[-.]/_/g}_RTM/src
DISTNAME=	nss-${VERSION_NSS}${NSS_SUFFIX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The root certificate bundle from the Mozilla Project

OPTIONS_DEFINE=	ETCSYMLINK
ETCSYMLINK_DESC=	Add symlink to /etc/ssl/cert.pem

USES=		perl5
USE_PERL5=	build
NO_WRKSUBDIR=	yes

CERTDIR?=	share/certs
PLIST_SUB+=	CERTDIR=${CERTDIR}

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# !!!  These versions are indented to track security/nss.        !!!
# !!!  Please DO NOT submit patches for new version until it has !!!
# !!!  been committed there first.                               !!!
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
VERSION_NSS=	3.15.5
#NSS_SUFFIX=	.with.ckbi.1.93
CERTDATA_TXT_PATH=	nss-${VERSION_NSS}/nss/lib/ckfw/builtins/certdata.txt
BUNDLE_PROCESSOR=	MAca-bundle.pl
SUB_FILES=	MAca-bundle.pl
SUB_LIST=	VERSION_NSS=${VERSION_NSS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:METCSYMLINK}
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
	@${RM} -rf ${WRKDIR}/nss-${VERSION_NSS}

do-build:	apply-slist
	@${PERL} ${WRKDIR}/${BUNDLE_PROCESSOR} \
	    < ${WRKDIR}/certdata.txt > \
	    ${WRKDIR}/ca-root-nss.crt

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CERTDIR}
	${INSTALL_DATA} ${WRKDIR}/ca-root-nss.crt ${STAGEDIR}${PREFIX}/${CERTDIR}

post-install:
.if ${PORT_OPTIONS:METCSYMLINK}
	${MKDIR} ${STAGEDIR}/etc/ssl
	${LN} -sf ${PREFIX}/${CERTDIR}/ca-root-nss.crt ${STAGEDIR}/etc/ssl/cert.pem
.endif

.include <bsd.port.mk>
