PORTNAME=	matterircd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.0
PORTREVISION=	13
CATEGORIES=	net-im irc

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	IRC bridge for Mattermost and Slack
WWW=		https://github.com/42wim/matterircd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 riscv64

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	42wim
USE_RC_SUBR=	matterircd

USERS=		matterircd
GROUPS=		matterircd

post-install:
	${INSTALL_DATA} ${WRKSRC}/matterircd.toml.example \
		${STAGEDIR}${PREFIX}/etc/matterircd.toml.sample

.include <bsd.port.mk>
