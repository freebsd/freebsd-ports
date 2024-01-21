PORTNAME=	fand
DISTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	corey@electrickite.org
COMMENT=	PWM cooling fan control daemon
WWW=		https://github.com/electrickite/fand

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	electrickite

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz \
		etc/rc.d/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|man$$|share/man|g' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
