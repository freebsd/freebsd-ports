# $FreeBSD$

PORTNAME=	matterircd
PORTVERSION=	0.17.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im irc

MAINTAINER=	norrland@nullbyte.se
COMMENT=	IRC bridge for Mattermost and Slack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	go>=1.8:lang/go

USE_RC_SUBR=	matterircd

USE_GITHUB=	yes
GH_ACCOUNT=	42wim
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

USERS=		matterircd
GROUPS=		matterircd

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/matterircd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/matterircd.toml.example \
		${STAGEDIR}${PREFIX}/etc/matterircd.toml.sample

.include <bsd.port.mk>
