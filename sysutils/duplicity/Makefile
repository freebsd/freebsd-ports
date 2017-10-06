# Created by: Gerhard Häring <gh@ghaering.de>
# $FreeBSD$

PORTNAME=	duplicity
PORTVERSION=	0.7.14
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/duplicity/0.7-series/${PORTVERSION}/+download/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Backup tool that uses librsync and GnuPG

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librsync.so:net/librsync2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fasteners>=0:devel/py-fasteners

USES=		python:2
USE_PYTHON=	autoplist distutils
USE_LDCONFIG=	yes

PORTDOCS=	CHANGELOG COPYING README README-REPO README-LOG

OPTIONS_DEFINE=		CLOUDFILES DOCS FTP FTPS GDOCS GIO NLS S3
OPTIONS_GROUP=		GPG SSH
OPTIONS_SINGLE=		GPG
OPTIONS_SINGLE_GPG=	GNUPG GNUPG2
OPTIONS_GROUP_SSH=	PARAMIKO PEXPECT
OPTIONS_DEFAULT=	FTP FTPS GNUPG PARAMIKO S3
CLOUDFILES_DESC=	CloudFiles backend
FTP_DESC=		FTP backend
FTPS_DESC=		FTPS backend
GDOCS_DESC=		Google Docs backend
GIO_DESC=		GIO backend
GPG_DESC=		GnuPG support
GNUPG_DESC=		Use GnuPG 1
GNUPG2_DESC=		Use GnuPG 2
S3_DESC=		Amazon S3 backend
SSH_DESC=		SSH/SCP/SFTP backend
PARAMIKO_DESC=		python ssh implementation
PEXPECT_DESC=		pexpect and use ssh binaries

CLOUDFILES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-cloudfiles>0:net/py-python-cloudfiles
FTP_RUN_DEPENDS=	ncftp>=3.2.2:ftp/ncftp3
FTPS_RUN_DEPENDS=	lftp>=3.7.15:ftp/lftp
GDOCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:devel/py-gdata
GIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject>0:devel/py-gobject \
					dbus>0:devel/dbus
GNUPG_RUN_DEPENDS=	gnupg1>=1.4.7:security/gnupg1
GNUPG2_RUN_DEPENDS=	gpg2:security/gnupg
NLS_USES=		gettext
PARAMIKO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.7.1:security/py-paramiko
PEXPECT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto>=1.6b:devel/py-boto

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '56,67d' \
		${WRKSRC}/setup.py

post-patch-PARAMIKO-off:
	@${FIND} ${WRKSRC}/${PORTNAME}/backends -type f -depth 1 \
		-name '*ssh_paramiko*' -delete

post-patch-PEXPECT-off:
	@${FIND} ${WRKSRC}/${PORTNAME}/backends -type f -depth 1 \
		-name '*ssh_pexpect*' -delete

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

post-patch-CLOUDFILES-off:
.for f in cfbackend _cf_cloudfiles _cf_pyrax
	@${RM} ${WRKSRC}/${PORTNAME}/backends/${f}.py
.endfor

post-patch-CLOUDFILES-on:
# Make pycloudfiles the default backend for cloudfiles, as pyrax isn't in the Ports Collection yet
# Use --cf-backend=pyrax arg when running duplicity to manually select pyrax as the backend
	@${REINPLACE_CMD} 's|"pyrax"|"cloudfiles"|' ${WRKSRC}/${PORTNAME}/globals.py

post-patch-GIO-off:
	@${RM} ${WRKSRC}/${PORTNAME}/backends/giobackend.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/duplicity/_librsync.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
