PORTNAME=	ntpstat
DISTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Print the ntpd or chronyd synchronisation status
WWW=		https://github.com/mlichvar/ntpstat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		gawk:lang/gawk

USES=		shebangfix

SHEBANG_FILES=	ntpstat

USE_GITHUB=	yes
GH_ACCOUNT=	mlichvar

MAKE_ARGS=	prefix="${STAGEDIR}${PREFIX}" mandir="${STAGEDIR}${PREFIX}/share"
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/awk/gawk/g' ${WRKSRC}/ntpstat

.include <bsd.port.mk>
