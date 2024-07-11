PORTNAME=	cjdns
DISTVERSIONPREFIX=	cjdns-v
DISTVERSION=	21.1
PORTREVISION=	2
CATEGORIES=	net security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Routing engine designed for security, scalability, speed
WWW=		https://github.com/cjdelisle/cjdns

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		21.1 is incompatible with Puython-3.11, and 22.0 fails to build, see https://github.com/hyperboria/bugs/issues/219

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake nodejs:build python
USE_GITHUB=	yes
GH_ACCOUNT=	cjdelisle
USE_RC_SUBR=	cjdns
SUB_FILES=	cjdns pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE}
PLIST_FILES=	bin/cjdroute bin/run-cjdroute share/man/man5/cjdroute.conf.5.gz

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/|${LOCALBASE}/etc/|g' \
		${WRKSRC}/contrib/sh/run-cjdroute.sh

do-build:
	@cd ${WRKSRC} && ./do

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cjdroute ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/sh/run-cjdroute.sh ${STAGEDIR}${PREFIX}/bin/run-cjdroute
	${INSTALL_MAN} ${WRKSRC}/doc/man/cjdroute.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

do-test:
	${WRKSRC}/cjdroute --bench

.include <bsd.port.mk>
