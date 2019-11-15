# Created by: Gerhard Häring <gh@ghaering.de>
# $FreeBSD$

PORTNAME=	duplicity
PORTVERSION=	0.8.07
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/duplicity/0.8-series/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Backup tool that uses librsync and GnuPG

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librsync.so:net/librsync2
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

CONFLICTS_INSTALL=	duplicity

SHEBANG_FILES=	bin/duplicity bin/rdiffdir

PORTDOCS=	CHANGELOG COPYING README README-REPO README-LOG

OPTIONS_DEFINE=		DOCS FTP FTPS GDOCS GIO NLS S3
OPTIONS_GROUP=		GPG
OPTIONS_SINGLE=		GPG
OPTIONS_SINGLE_GPG=	GNUPG GNUPG2
OPTIONS_DEFAULT=	FTP FTPS GNUPG2 S3
FTP_DESC=		FTP backend
FTPS_DESC=		FTPS backend
GDOCS_DESC=		Google Docs backend
GIO_DESC=		GIO backend
GPG_DESC=		GnuPG support
GNUPG_DESC=		Use GnuPG 1
GNUPG2_DESC=		Use GnuPG 2
S3_DESC=		Amazon S3 backend

FTP_RUN_DEPENDS=	ncftp>=3.2.2:ftp/ncftp3
FTPS_RUN_DEPENDS=	lftp>=3.7.15:ftp/lftp
GDOCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:devel/py-gdata@${PY_FLAVOR}
GIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject>0:devel/py-gobject@${PY_FLAVOR} \
					dbus>0:devel/dbus
GNUPG_RUN_DEPENDS=	gnupg1>=1.4.7:security/gnupg1
GNUPG2_RUN_DEPENDS=	gpg2:security/gnupg
NLS_USES=		gettext
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto>=1.6b:devel/py-boto@${PY_FLAVOR}

post-patch:
.for f in cfbackend _cf_cloudfiles _cf_pyrax
	@${RM} ${WRKSRC}/${PORTNAME}/backends/${f}.py
.endfor

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '55,63d' \
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

post-patch-GIO-off:
	@${RM} ${WRKSRC}/${PORTNAME}/backends/giobackend.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/duplicity/_librsync.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
