PORTNAME=	cdxgen
PORTVERSION=	12.1.2
CATEGORIES=	security devel

MAINTAINER=	miguel@ottria.eu
COMMENT=	CycloneDX SBOM generator CLI
WWW=		https://github.com/CycloneDX/cdxgen

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		nodejs:run shebangfix
SHEBANG_FILES=	bin/*.js contrib/jupyter-notebook-example/setup.sh

MASTER_SITES=	https://github.com/OTTRIA/freebsd-port-cdxgen-node-modules/raw/refs/heads/master/
DISTFILES+=	cdxgen-${PORTVERSION}-node_modules.tar.gz

USE_GITHUB=	yes
GH_ACCOUNT=	CycloneDX
GH_PROJECT=	cdxgen
GH_TAGNAME=	v${PORTVERSION}

NO_BUILD=	yes
INSTDIR=	${STAGEDIR}${PREFIX}/lib/node_modules/@cyclonedx/${PORTNAME}

do-install:
	${MKDIR} ${INSTDIR}
	${CP} -a ${WRKSRC}/ ${INSTDIR}/
	${CHMOD} +x ${INSTDIR}/bin/*.js
	${MKDIR} ${STAGEDIR}${PREFIX}/bin

.for bin in cdxgen evinse repl verify
	${LN} -sf ../lib/node_modules/@cyclonedx/${PORTNAME}/bin/${bin}.js ${STAGEDIR}${PREFIX}/bin/${bin}
.endfor

post-extract:
	cd ${WRKSRC} && ${TAR} -xzf ${DISTDIR}/cdxgen-${PORTVERSION}-node_modules.tar.gz

post-install:
	${RM} -rf ${INSTDIR}/.github ${INSTDIR}/test ${INSTDIR}/docs
	@${FIND} ${INSTDIR} -type f -perm -002 -exec ${CHMOD} o-w {} \;
	@${FIND} ${INSTDIR} -type d -perm -002 -exec ${CHMOD} o-w {} \;

.include <bsd.port.mk>
