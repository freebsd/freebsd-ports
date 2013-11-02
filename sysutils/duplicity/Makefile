# Created by: Gerhard Häring <gh@ghaering.de>
# $FreeBSD$

PORTNAME=	duplicity
PORTVERSION=	0.6.22
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/duplicity/0.6-series/${PORTVERSION}/+download/

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Backup tool that uses librsync and GnuPG

LIB_DEPENDS=	librsync.so:${PORTSDIR}/net/librsync
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

FETCH_ARGS=	-pRr

CONFLICTS=	duplicity-0.5.* duplicity-devel-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS DOCS SSH FTP FTPS S3 GDOCS CLOUDFILES GIO U1
OPTIONS_DEFAULT=SSH FTP FTPS S3
CLOUDFILES_DESC=Install CloudFiles backend
FTP_DESC=	Install FTP backend
FTPS_DESC=	Install FTPS backend
GDOCS_DESC=	Install Google Docs backend
GIO_DESC=	Install GIO backend
S3_DESC=	Install Amazon S3 backend
SSH_DESC=	Install SSH/SCP/SFTP backend
U1_DESC=	Install Ubuntu One backend

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSSH}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.7.1:${PORTSDIR}/security/py-paramiko
PLIST_SUB+=	SSH=""
.else
PLIST_SUB+=	SSH="@comment "
.endif

.if ${PORT_OPTIONS:MFTP}
RUN_DEPENDS+=	ncftp>=3.2.2:${PORTSDIR}/ftp/ncftp3
PLIST_SUB+=	FTP=""
.else
PLIST_SUB+=	FTP="@comment "
.endif

.if ${PORT_OPTIONS:MFTPS}
RUN_DEPENDS+=	lftp>=3.7.15:${PORTSDIR}/ftp/lftp
PLIST_SUB+=	FTPS=""
.else
PLIST_SUB+=	FTPS="@comment "
.endif

.if ${PORT_OPTIONS:MS3}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}boto>=1.6b:${PORTSDIR}/devel/py-boto
PLIST_SUB+=	S3=""
.else
PLIST_SUB+=	S3="@comment "
.endif

.if ${PORT_OPTIONS:MGDOCS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gdata>0:${PORTSDIR}/devel/py-gdata
PLIST_SUB+=	GDOCS=""
.else
PLIST_SUB+=	GDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MCLOUDFILES}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cloudfiles>0:${PORTSDIR}/net/py-cloudfiles
PLIST_SUB+=	CLOUDFILES=""
.else
PLIST_SUB+=	CLOUDFILES="@comment "
.endif

.if ${PORT_OPTIONS:MGIO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gobject>0:${PORTSDIR}/devel/py-gobject \
		dbus>0:${PORTSDIR}/devel/dbus
PLIST_SUB+=	GIO=""
.else
PLIST_SUB+=	GIO="@comment "
.endif

.if ${PORT_OPTIONS:MU1}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}httplib2>0:${PORTSDIR}/www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}oauthlib>0:${PORTSDIR}/security/py-oauthlib
PLIST_SUB+=	U1=""
.else
PLIST_SUB+=	U1="@comment "
.endif

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e '54,62d' \
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
	@${FIND} ${WRKSRC}/${PORTNAME}/backends -type f -depth 1 -name '*boto*' -delete
.endif
.if empty(PORT_OPTIONS:MGDOCS)
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/gdocsbackend.py
.endif
.if empty(PORT_OPTIONS:MCLOUDFILES)
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/cloudfilesbackend.py
.endif
.if empty(PORT_OPTIONS:MGIO)
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/giobackend.py
.endif
.if empty(PORT_OPTIONS:MU1)
	@${RM} -f ${WRKSRC}/${PORTNAME}/backends/u1backend.py
.endif

MAN1=		duplicity.1 rdiffdir.1

DOCFILES=	COPYING \
		README \
		README-REPO \
		README-LOG \
		tarfile-LICENSE \
		tarfile-CHANGES \
		CHANGELOG

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
