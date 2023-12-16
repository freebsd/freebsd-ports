PORTNAME=	routinator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${ROUTINATOR_UI_URL}/v${ROUTINATOR_UI_VERSION}/:0
DISTFILES+=	routinator-ui-build.tar.gz:0

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	RPKI signed route collector and validator
WWW=		https://github.com/NLnetLabs/routinator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	ring crate not ported to other architectures

RUN_DEPENDS=	rsync:net/rsync

USES=		cargo cpe
CPE_VENDOR=	nlnetlabs
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs

USE_RC_SUBR=	routinator

CARGO_FEATURES=	--no-default-features routinator-ui

SUB_FILES=	pkg-message
SUB_LIST+=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

ROUTINATOR_UI_VERSION=	0.3.4
ROUTINATOR_UI_URL=	https://github.com/NLnetLabs/routinator-ui/releases/download/

OPTIONS_DEFINE=	ASPA
OPTIONS_SUB=	yes

ASPA_DESC=	(Experimental) enable aspa support
ASPA_VARS=	CARGO_FEATURES+=aspa

post-patch:
	${REINPLACE_CMD} -e "s|DISTDIR|${DISTDIR}|" \
		${WRKSRC}/cargo-crates/routinator-ui-${ROUTINATOR_UI_VERSION}/build.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/routinator
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 \
		${STAGEDIR}${PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/routinator
	${INSTALL_DATA} ${WRKSRC}/etc/routinator.conf.example \
		${STAGEDIR}${PREFIX}/etc/routinator/routinator.conf.example

.include <bsd.port.mk>
