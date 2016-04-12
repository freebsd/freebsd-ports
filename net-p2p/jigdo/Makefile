# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	jigdo
PORTVERSION=	0.7.3
PORTREVISION=	8
CATEGORIES=	net-p2p
MASTER_SITES=	http://atterer.org/sites/atterer/files/2009-08/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility used to retrieve large files over the Internet

RUN_DEPENDS=	${LOCALBASE}/bin/wget:ftp/wget

USES=		gmake tar:bzip2
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		GUI BDB NLS
OPTIONS_DEFAULT=	BDB
OPTIONS_SUB=		yes

GUI_DESC=		GTK2 Graphical User Interface
BDB_DESC=		Berkeley DB support (for jigdo-file cache)

GUI_CONFIGURE_WITH=	gui
GUI_LIB_DEPENDS=	libgtk-x11-2.0.so:x11-toolkits/gtk20 \
			libcurl.so:ftp/curl
GUI_USES=		pkgconfig

BDB_CONFIGURE_ON=	--with-libdb=-l${BDB_LIB_CXX_NAME}
BDB_CONFIGURE_OFF=	--without-libdb
BDB_CPPFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LIBS=		-L${BDB_LIB_DIR}
BDB_USE=		BDB=48+

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jigdo-file

.include <bsd.port.mk>
