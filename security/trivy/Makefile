PORTNAME=	trivy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.66.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Security scanner written in go
WWW=		https://github.com/aquasecurity/trivy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	not supported, see https://github.com/aquasecurity/trivy/pull/9102

USES=		go:modules,1.24

GO_MODULE=	github.com/aquasecurity/trivy
GO_TARGET=	./cmd/trivy
GO_BUILDFLAGS= -ldflags=" \
		-extldflags '-static' \
		-X github.com/aquasecurity/trivy/pkg/version.ver=${DISTVERSION} \
		-s -w"

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/*.tpl ${STAGEDIR}${DATADIR}/
	${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		s#${DATADIR_REL}/bin#@(,,555) ${DATADIR_REL}/bin#; ' >> ${TMPPLIST}
	cat ${TMPPLIST}

.include <bsd.port.mk>
