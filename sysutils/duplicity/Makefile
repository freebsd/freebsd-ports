PORTNAME=	duplicity
DISTVERSION=	3.0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	PYPI

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Backup tool that uses librsync and GnuPG
WWW=		https://duplicity.gitlab.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pipx>0:devel/py-pipx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	librsync.so:net/librsync
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fasteners>=0:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR}

USES=		cpe localbase python shebangfix
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
USE_PYTHON=	autoplist noflavors pep517

SHEBANG_FILES=	duplicity/__main__.py

PORTDOCS=	AUTHORS.md README-LOG.md README-REPO.md README.md

OPTIONS_DEFINE=		B2 DOCS DROPBOX FTP FTPS GDOCS NLS S3
OPTIONS_DEFAULT=	B2 DROPBOX GNUPG2 S3
OPTIONS_GROUP=		GPG
OPTIONS_SINGLE=		GPG
OPTIONS_SINGLE_GPG=	GNUPG GNUPG2

B2_DESC=	Backblaze B2 backend
DROPBOX_DESC=	Dropbox backend
FTP_DESC=	FTP backend
FTPS_DESC=	FTPS backend
GDOCS_DESC=	Google Docs backend
GPG_DESC=	GnuPG support
GNUPG_DESC=	Use GnuPG 1
GNUPG2_DESC=	Use GnuPG 2
S3_DESC=	Amazon S3 backend

B2_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}b2sdk>=0.1.8:devel/py-b2sdk@${PY_FLAVOR}
DROPBOX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dropbox>0:www/py-dropbox@${PY_FLAVOR}
FTP_RUN_DEPENDS=	ncftp>=3.2.2:ftp/ncftp3
FTPS_RUN_DEPENDS=	lftp>=3.7.15:ftp/lftp
GDOCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyDrive2>0:www/py-pydrive2@${PY_FLAVOR}
GNUPG_RUN_DEPENDS=	gnupg1>=1.4.7:security/gnupg1
GNUPG2_RUN_DEPENDS=	gpg2:security/gnupg
NLS_USES=		gettext-tools
NLS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-setup.py
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/duplicity/_librsync*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
