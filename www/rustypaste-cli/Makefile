PORTNAME=	rustypaste-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	CLI tool for rustypaste
WWW=		https://github.com/orhun/rustypaste-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: error[E0080]: evaluation of constant value failed

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	orhun

CARGO_FEATURES=	--no-default-features

PLIST_DIRS=	${EXAMPLESDIR}
PLIST_FILES=	${EXAMPLESDIR}/config.toml \
		bin/rpaste

OPTIONS_DEFINE=	NATIVE_CERTS

NATIVE_CERTS_DESC=	Support using the OS TLS trust store
NATIVE_CERTS_VARS=	CARGO_FEATURES+=use-native-certs

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.toml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
