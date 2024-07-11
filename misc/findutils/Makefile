PORTNAME=	findutils
DISTVERSION=	4.10.0
CATEGORIES=	misc
MASTER_SITES=	GNU

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	GNU find utilities
WWW=		https://www.gnu.org/software/findutils/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix cpe gmake localbase tar:xz
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
i386_CONFIGURE_ARGS=	--disable-year2038
CONFIGURE_ARGS=	--program-prefix=g \
		--localstatedir=${LOCALSTATEDIR} \
		${${ARCH}_CONFIGURE_ARGS}

TEST_TARGET=	check
MAKE_ARGS=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INFO=		find find-maint

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

LOCALSTATEDIR?=	/var/db

.include <bsd.port.mk>
