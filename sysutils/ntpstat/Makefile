PORTNAME=	ntpstat
DISTVERSION=	0.6
CATEGORIES=	sysutils

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Print the ntpd or chronyd synchronisation status

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		gawk:lang/gawk

USES=		shebangfix

SHEBANG_FILES=	ntpstat

USE_GITHUB=	yes
GH_ACCOUNT=	mlichvar

MAKE_ENV=	STAGEDIR=${STAGEDIR} PREFIX=${PREFIX} MAN1PREFIX=${MAN1PREFIX}
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/awk/gawk/g' ${WRKSRC}/ntpstat

.include <bsd.port.mk>
