PORTNAME=	jigdo
PORTVERSION=	0.8.2
PORTREVISION=	1
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

MAKE_JOBS_UNSAFE=yes

CONFIGURE_ARGS=	--without-libdb

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jigdo-file

.include <bsd.port.mk>
