# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	cjdns
DISTVERSIONPREFIX=	cjdns-v
DISTVERSION=	20.2
CATEGORIES=	net security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Routing engine designed for security, scalability, speed

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build
BROKEN_armv6=		fails to build: Killing runaway build after 21600 seconds with no output
BROKEN_armv7=		fails to build: Killing runaway build after 21600 seconds with no output

BUILD_DEPENDS=	node:www/node \
		bash:shells/bash

USES=		gmake python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	cjdelisle
USE_RC_SUBR=	cjdns
SUB_FILES=	cjdns pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE}
PLIST_FILES=	bin/cjdroute bin/run-cjdroute man/man5/cjdroute.conf.5.gz

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/|${LOCALBASE}/etc/|g' \
		${WRKSRC}/contrib/sh/run-cjdroute.sh

do-build:
	@cd ${WRKSRC} && ./do

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cjdroute ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/sh/run-cjdroute.sh ${STAGEDIR}${PREFIX}/bin/run-cjdroute
	${INSTALL_MAN} ${WRKSRC}/doc/man/cjdroute.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5

do-test:
	${WRKSRC}/cjdroute --bench

.include <bsd.port.mk>
