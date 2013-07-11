# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	jigdo
PORTVERSION=	0.7.3
PORTREVISION=	7
CATEGORIES=	net-p2p
MASTER_SITES=	http://atterer.org/sites/atterer/files/2009-08/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility used to retrieve very large files over the Internet

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

MAN1=		jigdo-file.1 jigdo-lite.1 jigdo-mirror.1

USE_BZIP2=	yes
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WITH_BDB_VER?=	43

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		GUI BDB NLS
OPTIONS_DEFAULT=	BDB NLS

GUI_DESC=		Build the gtk2 gui
BDB_DESC=		Build with Berkeley DB support (for jigdo-file cache)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
CONFIGURE_ARGS+=	--with-gui
LIB_DEPENDS+=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		curl:${PORTSDIR}/ftp/curl
MAN1+=		jigdo.1
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=--without-gui
PLIST_SUB+=	GUI="@comment "
.endif

.if ${PORT_OPTIONS:MBDB}
CONFIGURE_ENV+=	LIBS=-L${BDB_LIB_DIR}
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
CONFIGURE_ARGS+=--with-libdb=-l${BDB_LIB_CXX_NAME}
USE_BDB=	${WITH_BDB_VER}
.else
CONFIGURE_ARGS+=--without-libdb
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/jigdo-file

.include <bsd.port.mk>
