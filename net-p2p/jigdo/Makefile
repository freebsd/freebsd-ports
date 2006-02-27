# ports collection makefile for:	jigdo
# Date created:				23 July 2002
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	jigdo
PORTVERSION=	0.7.1
CATEGORIES=	net-p2p
MASTER_SITES=	http://atterer.net/jigdo/

MAINTAINER=	bra@fsn.hu
COMMENT=	A utility used to retrieve very large files over the Internet

BUILD_DEPENDS=	libwww-config:${PORTSDIR}/www/libwww \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

MAN1=		jigdo-file.1 jigdo-lite.1 jigdo-mirror.1

USE_BZIP2=	yes
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	"CPPFLAGS=-I${LOCALBASE}/include -I${LOCALBASE}/include/db3" \
		LIBS=-L${LOCALBASE}/lib

OPTIONS=	GUI "Build the gtk2 gui" off \
		DB3 "Build with BDB3 support" on \
		NLS "Native Language Support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
NOT_FOR_ARCHS+=	alpha
.endif

.if defined(WITH_GUI)
CONFIGURE_ARGS+=	--with-gui
LIB_DEPENDS+=	gtk-x11-2.0:\${PORTSDIR}/x11-toolkits/gtk20
MAN1+=	jigdo.1
PLIST_SUB+=	SUB_GUI=""
.else
CONFIGURE_ARGS+=	--without-gui
PLIST_SUB+=	SUB_GUI="@comment "
.endif

.if defined(WITH_DB3)
CONFIGURE_ARGS+=	--with-libdb=-ldb3
#CONFIGURE_ENV+=	LDFLAGS=-ldb3
USE_BDB=	3
.else
CONFIGURE_ARGS+=	--without-libdb
.endif

.if defined(WITH_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment"
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/jigdo-file

.include <bsd.port.post.mk>
