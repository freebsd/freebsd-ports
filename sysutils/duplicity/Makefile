# Created by: Gerhard Häring <gh@ghaering.de>
# $FreeBSD$

PORTNAME=	duplicity
PORTVERSION=	0.6.24
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/duplicity/0.6-series/${PORTVERSION}/+download/

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Backup tool that uses librsync and GnuPG

LIB_DEPENDS=	librsync.so:${PORTSDIR}/net/librsync
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
				${PYTHON_PKGNAMEPREFIX}lockfile>=0:${PORTSDIR}/devel/py-lockfile

USES=		python:2
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS DOCS SSH FTP FTPS S3 GDOCS CLOUDFILES GIO
OPTIONS_DEFAULT=SSH FTP FTPS S3
CLOUDFILES_DESC=Install CloudFiles backend
FTP_DESC=	Install FTP backend
FTPS_DESC=	Install FTPS backend
GDOCS_DESC=	Install Google Docs backend
GIO_DESC=	Install GIO backend
S3_DESC=	Install Amazon S3 backend
SSH_DESC=	Install SSH/SCP/SFTP backend

PORTDOCS=	COPYING README README-REPO README-LOG tarfile-LICENSE \
			tarfile-CHANGES CHANGELOG

NLS_USES=			gettext
SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.7.1:${PORTSDIR}/security/py-paramiko
FTP_RUN_DEPENDS=	ncftp>=3.2.2:${PORTSDIR}/ftp/ncftp3
FTPS_RUN_DEPENDS=	lftp>=3.7.15:${PORTSDIR}/ftp/lftp
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto>=1.6b:${PORTSDIR}/devel/py-boto
GDOCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:${PORTSDIR}/devel/py-gdata
CLOUDFILES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudfiles>0:${PORTSDIR}/net/py-cloudfiles
GIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject>0:${PORTSDIR}/devel/py-gobject \
					dbus>0:${PORTSDIR}/devel/dbus

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e '56,67d' \
		${WRKSRC}/setup.py
.endif
.if empty(PORT_OPTIONS:MSSH)
	@${FIND} ${WRKSRC}/${PORTNAME}/backends -type f -depth 1 -name '*ssh*' -delete
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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
