PORTNAME=	cfssl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.5
PORTREVISION=	12
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cloudflare's PKI and TLS toolkit
WWW=		https://cfssl.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		go:modules gmake
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/cloudflare/cfssl

EXES=		cfssl cfssl-bundle cfssl-certinfo cfssl-newkey cfssl-scan cfssljson mkbundle multirootca

PLIST_FILES=	${EXES:S/^/bin\//}

CFSSL_EXTRA_TARGETS=	bin/goose
PLIST_FILES+=	${CFSSL_EXTRA_TARGETS}
USE_RC_SUBR=	${PORTNAME}
USERS=	cfssl
GROUPS=	cfssl
# installs a file to the same path
CONFLICTS=	goose

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

pre-configure:
	${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' ${WRKSRC}/cli/version/version.go

# the project uses Makefile for build and installation
do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} all ${CFSSL_EXTRA_TARGETS}

do-install:
	# Makefile is used but the install target uses go install.
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} GOBIN=${STAGEDIR}${PREFIX}/bin ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} install
.for F in cfssl cfssl-certinfo multirootca
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${F}
.endfor

	${INSTALL} -d ${STAGEDIR}${DATADIR}
.for D in certdb/sqlite certdb/pg certdb/mysql
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${D} ${STAGEDIR}${DATADIR}
.endfor

.for F in ${CFSSL_EXTRA_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${F} ${STAGEDIR}/${PREFIX}/${F}
.endfor

.include <bsd.port.mk>
