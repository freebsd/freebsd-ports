# Created by: Gerhard Häring <gh@ghaering.de>
# $FreeBSD$

PORTNAME=	duplicity
PORTVERSION=	0.8.17
CATEGORIES=	sysutils
MASTER_SITES=	https://code.launchpad.net/duplicity/0.8-series/${PORTVERSION}/+download/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Backup tool that uses librsync and GnuPG

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	librsync.so:net/librsync
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fasteners>=0:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

USES=		localbase python shebangfix
USE_PYTHON=	autoplist distutils noflavors
USE_LDCONFIG=	yes

SHEBANG_FILES=	bin/duplicity bin/rdiffdir

PORTDOCS=	CHANGELOG.md COPYING README.md README-REPO.md README-LOG.md

POST_PLIST=	trim-duplicity-testing

OPTIONS_DEFINE=		B2 DOCS FTP FTPS GDOCS NLS S3
OPTIONS_GROUP=		GPG
OPTIONS_SINGLE=		GPG
OPTIONS_SINGLE_GPG=	GNUPG GNUPG2
OPTIONS_DEFAULT=	B2 FTP FTPS GNUPG2 S3

B2_DESC=		Backblaze B2 backend
FTP_DESC=		FTP backend
FTPS_DESC=		FTPS backend
GDOCS_DESC=		Google Docs backend
GPG_DESC=		GnuPG support
GNUPG_DESC=		Use GnuPG 1
GNUPG2_DESC=		Use GnuPG 2
S3_DESC=		Amazon S3 backend

B2_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}b2sdk>=0.1.8:devel/py-b2sdk@${PY_FLAVOR}
FTP_RUN_DEPENDS=	ncftp>=3.2.2:ftp/ncftp3
FTPS_RUN_DEPENDS=	lftp>=3.7.15:ftp/lftp
GDOCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydrive>0:devel/py-pydrive@${PY_FLAVOR}
GNUPG_RUN_DEPENDS=	gnupg1>=1.4.7:security/gnupg1
GNUPG2_RUN_DEPENDS=	gpg2:security/gnupg
NLS_USES=		gettext
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto>=1.6b:devel/py-boto@${PY_FLAVOR}

post-patch:
.for f in cfbackend _cf_cloudfiles _cf_pyrax giobackend
	@${RM} ${WRKSRC}/${PORTNAME}/backends/${f}.py
.endfor

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '109,133d' \
		${WRKSRC}/setup.py

post-patch-FTP-off:
	@${RM} ${WRKSRC}/${PORTNAME}/backends/ftpbackend.py

post-patch-FTPS-off:
	@${RM} ${WRKSRC}/${PORTNAME}/backends/ftpsbackend.py

post-patch-S3-off:
.for f in botobackend _boto_multi _boto_single
	@${RM} ${WRKSRC}/${PORTNAME}/backends/${f}.py
.endfor

post-patch-GDOCS-off:
	@${RM} ${WRKSRC}/${PORTNAME}/backends/gdocsbackend.py

post-patch-B2-off:
	@${RM} ${WRKSRC}/${PORTNAME}/backends/b2backend.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/duplicity/_librsync*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

trim-duplicity-testing:
	@${REINPLACE_CMD} '/\/testing\//d' ${TMPPLIST}

.include <bsd.port.mk>
