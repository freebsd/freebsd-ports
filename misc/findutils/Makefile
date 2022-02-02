# Created by: Robert Withrow <witr@rwwa.com>

PORTNAME=	findutils
PORTVERSION=	4.9.0
CATEGORIES=	misc
MASTER_SITES=	GNU

MAINTAINER=	aehlig@linta.de
COMMENT=	GNU find utilities

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix cpe gmake localbase tar:xz
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-prefix=g --localstatedir=${LOCALSTATEDIR}

MAKE_ARGS=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INFO=		find find-maint

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

LOCALSTATEDIR?=	/var/db

.include <bsd.port.mk>
