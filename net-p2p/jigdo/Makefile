PORTNAME=	jigdo
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	https://www.einval.com/~steve/software/jigdo/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility used to retrieve large files over the Internet
WWW=		https://www.einval.com/~steve/software/jigdo/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/README

BUILD_DEPENDS=	brename>0:sysutils/brename \
		docbook-utils>0:textproc/docbook-utils \
		sgmlformat>0:textproc/sgmlformat
RUN_DEPENDS=	${LOCALBASE}/bin/wget:ftp/wget

USES=		gmake localbase tar:xz

USE_CXXSTD=	c++98
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-libdb

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jigdo-file

.include <bsd.port.mk>
