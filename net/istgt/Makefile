# Created by: Daisuke Aoyama <aoyama@peach.ne.jp>
# $FreeBSD$

PORTNAME=	istgt
PORTVERSION=	20121028
CATEGORIES=	net
MASTER_SITES=	http://www.peach.ne.jp/archives/istgt/

MAINTAINER=	aoyama@peach.ne.jp
COMMENT=	iSCSI target for openSUSE/Debian/NetBSD/FreeBSD

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes

MAN1=		istgt.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/istgt \
		bin/istgtcontrol \
		etc/rc.d/istgt \
		%%ETCDIR%%/auth.conf.sample \
		%%ETCDIR%%/istgt.conf.sample \
		%%ETCDIR%%/istgt.large.conf.sample \
		%%ETCDIR%%/istgtcontrol.conf.sample
PLIST_DIRSTRY=	%%ETCDIR%%
PORTDOCS=	${DOCS:T}

DOCS=		ChangeLog.jp README doc/QUICKSTART doc/QUICKSTART.jp

OPTIONS_DEFINE=	SYMLNKDEV VBOXVD
OPTIONS_DEFAULT=
SYMLNKDEV_DESC=	Allow symbolic link for device file
VBOXVD_DESC=	Build with VBox VD support(no X11 required)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSYMLNKDEV}
CONFIGURE_ARGS+=	--enable-symlink-device
.endif

.if ${PORT_OPTIONS:MVBOXVD}
. if ${OSVERSION} < 802000
VBOX_WRKSRC=	`${MAKE} -C ${PORTSDIR}/emulators/virtualbox-ose-legacy -V WRKSRC`
RUN_DEPENDS+=	${LOCALBASE}/lib/virtualbox/VBoxRT.so:${PORTSDIR}/emulators/virtualbox-ose-legacy
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/emulators/virtualbox-ose-legacy:patch
CONFIGURE_ARGS+=	--with-vbox=${VBOX_WRKSRC}/include
. else
VBOX_WRKSRC=	`${MAKE} -C ${PORTSDIR}/emulators/virtualbox-ose -V WRKSRC`
RUN_DEPENDS+=	${LOCALBASE}/lib/virtualbox/VBoxRT.so:${PORTSDIR}/emulators/virtualbox-ose
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/emulators/virtualbox-ose:patch
CONFIGURE_ARGS+=	--with-vbox=${VBOX_WRKSRC}/include
. endif
.endif

post-extract:
	@${REINPLACE_CMD} -e '/\/doc\/istgt/d' ${WRKSRC}/doc/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
