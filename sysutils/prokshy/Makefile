PORTNAME=	prokshy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Small and lightweight bhyve agent (${FLAVOR})

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	rc cli
FLAVOR?=	${FLAVORS:[1]}

cli_PKGNAMESUFFIX=	-cli
cli_CONFLICTS_INSTALL=	${PORTNAME}
rc_RUN_DEPENDS=		unixexec:sysutils/unixexec
rc_CONFLICTS_INSTALL=	${PORTNAME}-cli

.if ${FLAVOR} == cli
USES=		python shebangfix
.endif
USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF

.if ${FLAVOR} == cli
SHEBANG_FILES=	cli.py
.endif

NO_ARCH=	yes
NO_BUILD=	yes

.if ${FLAVOR} == rc
PLIST_FILES=	etc/rc.d/${PORTNAME} \
		libexec/${PORTNAME}/main.sh
.elif ${FLAVOR} == cli
PLIST_FILES=	bin/${PORTNAME}
.endif
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
.if ${FLAVOR} == rc
.for script in prokshy.rc main.sh
	@${REINPLACE_CMD} "s|/usr/local|${PREFIX}|g" ${WRKSRC}/${script}
.endfor
.endif

do-install:
.if ${FLAVOR} == rc
	${INSTALL_SCRIPT} ${WRKSRC}/prokshy.rc ${STAGEDIR}${PREFIX}/etc/rc.d/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/main.sh ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/main.sh
.elif ${FLAVOR} == cli
	${INSTALL_SCRIPT} ${WRKSRC}/cli.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
