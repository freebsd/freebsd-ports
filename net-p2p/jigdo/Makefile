PORTNAME=	jigdo
PORTVERSION=	0.8.2
CATEGORIES=	net-p2p
MASTER_SITES=	https://www.einval.com/~steve/software/jigdo/download/
DISTNAME=	jigdo-0.8.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility used to retrieve large files over the Internet
WWW=		https://www.einval.com/~steve/software/jigdo/

LICENSE_FILE=	${WRKDIR}/README

BUILD_DEPENDS=	brename>0:sysutils/brename \
		docbook-utils>0:textproc/docbook-utils \
		sgmlformat>0:textproc/sgmlformat
RUN_DEPENDS=	${LOCALBASE}/bin/wget:ftp/wget

USES=		gmake tar:xz localbase

USE_CXXSTD=	c++98
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=		BDB NLS
OPTIONS_DEFAULT=	BDB
OPTIONS_SUB=		yes

BDB_DESC=		Berkeley DB support (for jigdo-file cache)

BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-libdb=-l${BDB_LIB_CXX_NAME}
BDB_CONFIGURE_OFF=	--without-libdb
BDB_CPPFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LIBS=		-L${BDB_LIB_DIR}

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jigdo-file

.include <bsd.port.mk>
