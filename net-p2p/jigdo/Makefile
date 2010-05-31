# ports collection makefile for:	jigdo
# Date created:				23 July 2002
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	jigdo
PORTVERSION=	0.7.3
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	http://atterer.net/jigdo/

MAINTAINER=	bra@fsn.hu
COMMENT=	A utility used to retrieve very large files over the Internet

BUILD_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

MAN1=		jigdo-file.1 jigdo-lite.1 jigdo-mirror.1

USE_BZIP2=	yes
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WITH_BDB_VER?=	43

CONFIGURE_ENV+=	"CPPFLAGS=-I${LOCALBASE}/include"

OPTIONS=	GUI "Build the gtk2 gui" off \
		BDB "Build with Berkeley DB support (for jigdo-file cache)" on \
		NLS "Native Language Support" on

.include <bsd.port.pre.mk>

.if defined(WITH_GUI)
CONFIGURE_ARGS+=	--with-gui
LIB_DEPENDS+=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		curl:${PORTSDIR}/ftp/curl
MAN1+=		jigdo.1
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=--without-gui
PLIST_SUB+=	GUI="@comment "
.endif

.if !defined(WITHOUT_BDB)
CONFIGURE_ENV+=	CPPFLAGS=-I${BDB_INCLUDE_DIR} \
		LIBS=-L${BDB_LIB_DIR}
CONFIGURE_ARGS+=--with-libdb=-l${BDB_LIB_CXX_NAME}
USE_BDB=	${WITH_BDB_VER}
.else
CONFIGURE_ARGS+=--without-libdb
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/jigdo-file

.include <bsd.port.post.mk>
