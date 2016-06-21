# Created by: Gerhard Häring <gh@ghaering.de>
# $FreeBSD$

PORTNAME=	duplicity
PORTVERSION=	0.7.07.1
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/duplicity/0.7-series/${PORTVERSION}/+download/

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Backup tool that uses librsync and GnuPG

LIB_DEPENDS=	librsync.so:net/librsync1
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>=0:devel/py-lockfile

USES=		python:2
USE_PYTHON=	autoplist distutils
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		CLOUDFILES DOCS FTP FTPS GDOCS GIO NLS S3
OPTIONS_GROUP=		GPG SSH
OPTIONS_SINGLE=		GPG
OPTIONS_SINGLE_GPG=	GNUPG GNUPG2
OPTIONS_GROUP_SSH=	PARAMIKO PEXPECT
OPTIONS_DEFAULT=	FTP FTPS GNUPG PARAMIKO S3
CLOUDFILES_DESC=	Install CloudFiles backend
FTP_DESC=		Install FTP backend
FTPS_DESC=		Install FTPS backend
GDOCS_DESC=		Install Google Docs backend
GIO_DESC=		Install GIO backend
GPG_DESC=		Install GnuPG
GNUPG_DESC=		Install GnuPG 1
GNUPG2_DESC=		Install GnuPG 2
S3_DESC=		Install Amazon S3 backend
SSH_DESC=		Install SSH/SCP/SFTP backend
PARAMIKO_DESC=		Install python ssh implementation
PEXPECT_DESC=		Install pexpect and use ssh binaries

PORTDOCS=	CHANGELOG COPYING README README-REPO README-LOG

CLOUDFILES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudfiles>0:net/py-cloudfiles
FTP_RUN_DEPENDS=	ncftp>=3.2.2:ftp/ncftp3
FTPS_RUN_DEPENDS=	lftp>=3.7.15:ftp/lftp
GDOCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:devel/py-gdata
GIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject>0:devel/py-gobject \
					dbus>0:devel/dbus
GNUPG_RUN_DEPENDS=	gnupg1>=1.4.7:security/gnupg1
GNUPG2_RUN_DEPENDS=	gpg2:security/gnupg
NLS_USES=		gettext
PARAMIKO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.7.1:security/py-paramiko
PEXPECT_RUN_DEPENDS=	pexpect:misc/py-pexpect
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto>=1.6b:devel/py-boto

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e '56,67d' \
		${WRKSRC}/setup.py
.endif
.if empty(PORT_OPTIONS:MPARAMIKO)
	@${FIND} ${WRKSRC}/${PORTNAME}/backends -type f -depth 1 -name '*ssh_paramiko*' -delete
.endif
.if empty(PORT_OPTIONS:MPEXPECT)
	@${FIND} ${WRKSRC}/${PORTNAME}/backends -type f -depth 1 -name '*ssh_pexpect*' -delete
.endif
.if empty(PORT_OPTIONS:MFTP)
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/ftpbackend.py
.endif
.if empty(PORT_OPTIONS:MFTPS)
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/ftpsbackend.py
.endif
.if empty(PORT_OPTIONS:MS3)
.for f in botobackend _boto_multi _boto_single
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/${f}.py
.endfor
.endif
.if empty(PORT_OPTIONS:MGDOCS)
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/gdocsbackend.py
.endif
.if empty(PORT_OPTIONS:MCLOUDFILES)
.for f in cfbackend _cf_cloudfiles _cf_pyrax
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/${f}.py
.endfor
.else
# Make pycloudfiles the default backend for cloudfiles, as pyrax isn't in the Ports Collection yet
# Use --cf-backend=pyrax arg when running duplicity to manually select pyrax as the backend
	@${REINPLACE_CMD} 's|"pyrax"|"cloudfiles"|' ${WRKSRC}/${PORTNAME}/globals.py
.endif
.if empty(PORT_OPTIONS:MGIO)
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/giobackend.py
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/duplicity/_librsync.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
