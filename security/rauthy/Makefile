PORTNAME=	rauthy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.35.2
CATEGORIES=	security

MAINTAINER=	daniel@morante.net
COMMENT=	OpenID Connect Identity & Access Management server
WWW=		https://sebadob.github.io/rauthy/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	sebadob
USE_RC_SUBR=	rauthy

CARGO_INSTALL_PATH=	src/bin
CARGO_ENV+=	OPENSSL_NO_VENDOR=1

SUB_FILES=	rauthy
SUB_LIST=	USER=${USERS} \
		GROUP=${GROUPS} \
		ETCDIR=${ETCDIR}

USERS=		rauthy
GROUPS=		rauthy

PLIST_DIRS=	${ETCDIR} \
		${EXAMPLESDIR}
PLIST_FILES=	bin/rauthy \
		"@sample ${ETCDIR}/rauthy.toml.sample" \
		${EXAMPLESDIR}/config.toml

post-extract:
	@${MKDIR} ${WRKSRC}/static
	@cd ${WRKSRC} && ${TAR} -xf assets/static_html/static_v1.tar.gz
	@cd ${WRKSRC} && ${TAR} -xf assets/static_html/templates_html.tar.gz

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/rauthy.toml.sample \
		${STAGEDIR}${ETCDIR}/rauthy.toml.sample
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.toml \
		${STAGEDIR}${EXAMPLESDIR}/config.toml

.include "${.CURDIR}/Makefile.crates"
.include <bsd.port.mk>
