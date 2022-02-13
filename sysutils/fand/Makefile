PORTNAME=	fand
DISTVERSION=	0.2.3
CATEGORIES=	sysutils

MAINTAINER=	corey@electrickite.org
COMMENT=	PWM cooling fan control daemon

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	electrickite

PLIST_FILES=	sbin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz \
		etc/rc.d/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
