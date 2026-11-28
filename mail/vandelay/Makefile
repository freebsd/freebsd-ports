PORTNAME=	vandelay
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	mail

MAINTAINER=	jsi@jules.de
COMMENT=	JMAP account migration and backup utility
WWW=		https://github.com/stalwartlabs/vandelay

LICENSE=		AGPLv3 SELv2
LICENSE_COMB=		dual
LICENSE_NAME_SELv2=	Stalwart Enterprise License 2.0
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_SELv2=	${WRKSRC}/LICENSES/LicenseRef-SEL.txt
LICENSE_PERMS_SELv2=	none

USES=		cargo pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	stalwartlabs

# files/patch-Cargo.toml turns off the bundled-sqlite default feature of
# vandelay-engine, so that the system SQLite is used.
CARGO_INSTALL_PATH=	crates/vandelay

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
