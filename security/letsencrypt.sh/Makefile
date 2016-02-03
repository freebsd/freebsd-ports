# $FreeBSD$

PORTNAME=	letsencrypt.sh
PORTVERSION=	0.0.0.20160116
CATEGORIES=	security

MAINTAINER=	sascha@root-login.org
COMMENT=	Pure BASH Lets Encrypt client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		curl:${PORTSDIR}/ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	lukas2511
GH_TAGNAME=	23b0ef5

NO_ARCH=	yes
NO_BUILD=	yes
USES=		shebangfix

PERIODIC_DIRS=	etc/periodic/monthly
PERIODIC_FILES=	000.letsencrypt.sh

PLIST_DIRS=	%%ETCDIR%%/.acme-challenges
PLIST_FILES=	bin/letsencrypt.sh \
		%%ETCDIR%%/config.sh.example \
		%%ETCDIR%%/domains.txt.example \
		etc/periodic/monthly/000.letsencrypt.sh

SUB_FILES=	000.letsencrypt.sh pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

SHEBANG_FILES=	config.sh.example

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/.acme-challenges ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}
	${INSTALL_DATA} ${WRKSRC}/config.sh.example ${STAGEDIR}${ETCDIR}/config.sh.example
	${INSTALL_DATA} ${WRKSRC}/domains.txt.example ${STAGEDIR}${ETCDIR}/domains.txt.example
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODIC_FILES} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}/${PERIODIC_FILES}

.include <bsd.port.mk>
