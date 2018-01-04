# Created by: Daisuke Aoyama <aoyama@peach.ne.jp>
# $FreeBSD$

PORTNAME=	istgt
PORTVERSION=	20150713
CATEGORIES=	net
MASTER_SITES=	http://www.peach.ne.jp/archives/istgt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	iSCSI target for openSUSE/Debian/NetBSD/FreeBSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes

PORTDOCS=	${DOCFILES:T}
DOCFILES=	ChangeLog.jp README doc/QUICKSTART doc/QUICKSTART.jp

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	SYMLNKDEV VBOXVD DOCS

SYMLNKDEV_DESC=	Allow symbolic link for device file
VBOXVD_DESC=	VirtualBox VD support (no X11 required)

SYMLNKDEV_CONFIGURE_ON=	--enable-symlink-device

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVBOXVD}
VBOX_WRKSRC=	`${MAKE} -C ${PORTSDIR}/emulators/virtualbox-ose -V WRKSRC`
RUN_DEPENDS+=	${LOCALBASE}/lib/virtualbox/VBoxRT.so:emulators/virtualbox-ose
BUILD_DEPENDS+=	${NONEXISTENT}:emulators/virtualbox-ose:patch
CONFIGURE_ARGS+=	--with-vbox=${VBOX_WRKSRC}/include
.endif

post-extract:
	@${REINPLACE_CMD} -e '/\/doc\/istgt/d' ${WRKSRC}/doc/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
