PORTNAME=	gotosocial
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	https://codeberg.org/superseriousbusiness/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTFILES=	${PORTNAME}-${DISTVERSION}-source-code.tar.gz ${PORTNAME}_${DISTVERSION}_web-assets.tar.gz

MAINTAINER=	tilde@ultros.pro
COMMENT=	Golang fediverse server
WWW=		https://docs.gotosocial.org/en/latest/

LICENSE=			AGPLv3 CC-BY-3.0 CC-BY-SA-4.0 MIT OFL11
LICENSE_COMB=			multi
LICENSE_FILE_AGPLv3=		${WRKSRC}/LICENSE
LICENSE_FILE_CC-BY-3.0=		${WRKSRC}/CC-BY-3.0
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/CC-BY-SA-4.0
LICENSE_FILE_MIT=		${WRKSRC}/MIT
LICENSE_FILE_OFL11=		${WRKSRC}/OFL11

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386
ONLY_FOR_ARCHS_REASON=	https://gitlab.com/cznic/libc/-/issues/15

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}

GO_TARGET=	./cmd/gotosocial
GO_BUILDFLAGS+=	-tags "netgo osusergo static_build kvformat ${WITH_DEBUG:Ddebugenv}" \
 	-ldflags="${STRIP} -w -extldflags '-static' -X 'main.Version=${PKGVERSION}'"
CGO_ENABLED=	0

SUB_LIST=	DBDIR="${DBDIR}" \
		GROUP="${GROUPS}" \
		USER="${USERS}" \
		WWWDIR="${WWWDIR}"

USERS=		gotosocial
GROUPS=		gotosocial

NO_WRKSUBDIR=	yes

DBDIR=		/var/db/${PORTNAME}

PLIST_SUB=	WWWDIR="${WWWDIR}"

TESTING_UNSAFE=	FAIL    codeberg.org/superseriousbusiness/gotosocial/internal/log

post-extract:
	${SED} -n "1, 27p" ${WRKSRC}/web/assets/Fork-Awesome/LICENSES \
		> ${WRKSRC}/MIT
	${SED} -n "28, 352p" ${WRKSRC}/web/assets/Fork-Awesome/LICENSES \
		> ${WRKSRC}/CC-BY-3.0
	${SED} -n "353, 452p" ${WRKSRC}/web/assets/Fork-Awesome/LICENSES \
		> ${WRKSRC}/OFL11
	${HEAD} -n 8 ${WRKSRC}/web/assets/LICENSE > ${WRKSRC}/CC-BY-SA-4.0
	${TAIL} -n 1 ${WRKSRC}/web/assets/LICENSE >> ${WRKSRC}/MIT
	${ECHO} >> ${WRKSRC}/MIT
	${RM} ${WRKSRC}/web/assets/LICENSE
	${RM} ${WRKSRC}/web/assets/Fork-Awesome/LICENSES
	${RM} ${WRKSRC}/web/assets/fonts/OFL.txt
	${RM} ${WRKSRC}/web/assets/Fork-Awesome/CONTRIBUTORS.md

post-patch:
	${REINPLACE_CMD} -e 's,GTS_DB_TYPE="postgres",#&,' ${WRKSRC}/scripts/test.sh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/example/config.yaml \
		${STAGEDIR}${ETCDIR}/config.yaml.sample
	(cd ${WRKSRC}/web && ${COPYTREE_SHARE} "assets template" ${STAGEDIR}${WWWDIR})

do-test:
	(cd ${GO_WRKSRC}; \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off scripts/test.sh)

.include <bsd.port.mk>
