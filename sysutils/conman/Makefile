PORTNAME=	conman
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	conman-
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Serial Console Management Program

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libinotify.so:devel/libinotify
RUN_DEPENDS=	expect>0:lang/expect \
		freeipmi>1.0.4:sysutils/freeipmi

USES=	autoreconf gmake shebangfix perl5

USE_RC_SUBR=	conmand

USE_GITHUB=	yes
GH_ACCOUNT=	dun

GNU_CONFIGURE=	yes

ETCDIR=	${PREFIX}/etc
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}

SHEBANG_GLOB=	*.exp conmen
SHEBANG_LANG=	expect

MAKE_ARGS+=	CC="${CC}" PREFIX="${PREFIX}"

CFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib -linotify

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/conman
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/conmand
	${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
