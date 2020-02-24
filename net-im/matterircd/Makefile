# $FreeBSD$

PORTNAME=	matterircd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.2
PORTREVISION=	1
CATEGORIES=	net-im irc

MAINTAINER=	norrland@nullbyte.se
COMMENT=	IRC bridge for Mattermost and Slack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386

USES=		go:modules

USE_RC_SUBR=	matterircd

USE_GITHUB=	yes
GH_ACCOUNT=	42wim

USERS=		matterircd
GROUPS=		matterircd

post-install:
	${INSTALL_DATA} ${WRKSRC}/matterircd.toml.example \
		${STAGEDIR}${PREFIX}/etc/matterircd.toml.sample

.include <bsd.port.mk>
