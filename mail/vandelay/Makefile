PORTNAME=	vandelay
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.15
CATEGORIES=	mail

MAINTAINER=	jsi@jules.de
COMMENT=	JMAP account migration and backup utility
WWW=		https://github.com/stalwartlabs/vandelay

LICENSE=		APACHE20 MIT
LICENSE_COMB=		dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSES/Apache-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

USES=		cargo pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	stalwartlabs

CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/vandelay
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS EXPORT_SCRIPT

EXPORT_SCRIPT_DESC=	Python script to export archives to Maildir/JSON
EXPORT_SCRIPT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
EXPORT_SCRIPT_USES=	python:run shebangfix
EXPORT_SCRIPT_PLIST_FILES=	bin/vandelay-export-archive
EXPORT_SCRIPT_VARS=	SHEBANG_FILES=scripts/export_archive.py

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXPORT_SCRIPT-on:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/export_archive.py \
		${STAGEDIR}${PREFIX}/bin/vandelay-export-archive

.include <bsd.port.mk>
