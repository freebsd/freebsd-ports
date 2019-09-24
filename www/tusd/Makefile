# $FreeBSD$

PORTNAME=	tusd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	www

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Reference server implementation in Go of tus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	tus
GO_TARGET=	cmd/tusd/main.go:tusd

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

USERS=		www
GROUPS=		www

TUSD_UPLOAD_DIR?=	/var/spool/tusd

USE_RC_SUBR=	tusd
SUB_FILES=	tusd
SUB_LIST=	TUSD_USER=${USERS} \
		TUSD_GROUP=${GROUPS} \
		TUSD_UPLOAD_DIR=${TUSD_UPLOAD_DIR}

PLIST_SUB+=	${SUB_LIST}

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/tusd ${STAGEDIR}${PREFIX}/bin/tusd
	${MKDIR} ${STAGEDIR}${TUSD_UPLOAD_DIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/hooks.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/apache2.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/nginx.conf ${STAGEDIR}${EXAMPLESDIR}
.for FILE in post-create post-finish post-receive post-terminate pre-create
	${INSTALL_SCRIPT} ${WRKSRC}/examples/hooks/${FILE} ${STAGEDIR}${EXAMPLESDIR}/hooks
.endfor

.include <bsd.port.mk>
