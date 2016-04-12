# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	volman
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	uffe@uffe.org
COMMENT=	FreeBSD specific volume manager

USE_GITHUB=	yes
GH_ACCOUNT=	uffejakobsen

USE_RC_SUBR=	volmand
VM_SUB_FILES=	vmount volmand

OPTIONS_DEFINE=	OPENBOX NTFS3G
OPENBOX_DESC=	Openbox pipemenu script
NTFS3G_DESC=	Use fusefs-ntfs extensions

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENBOX}
VM_SUB_FILES+=	obvolman
RUN_DEPENDS+=	${LOCALBASE}/bin/xmessage:x11/xmessage
PLIST_SUB+=	OPENBOX=""
.else
PLIST_SUB+=	OPENBOX="@comment "
.endif

.if ${PORT_OPTIONS:MNTFS3G}
RUN_DEPENDS+=	${LOCALBASE}/bin/ntfs-3g:sysutils/fusefs-ntfs
SUB_LIST+=	RCFUSEFS=" fusefs"
.else
SUB_LIST+=	RCFUSEFS=""
.endif

do-build:
.for file in ${VM_SUB_FILES}
	${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${WRKSRC}/${file}.in >${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/volmand ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/vmount ${STAGEDIR}${PREFIX}/bin
.if defined(WITH_OPENBOX)
	${INSTALL_SCRIPT} ${WRKSRC}/obvolman ${STAGEDIR}${PREFIX}/bin
.endif
	${INSTALL_DATA} ${WRKSRC}/volman.conf ${STAGEDIR}${PREFIX}/etc/volman.conf.sample

.include <bsd.port.mk>
