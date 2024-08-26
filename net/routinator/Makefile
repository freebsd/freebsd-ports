PORTNAME=	routinator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	RPKI signed route collector and validator
WWW=		https://github.com/NLnetLabs/routinator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	ring crate not ported to other architectures

RUN_DEPENDS=	rsync:net/rsync

USES=		cargo cpe
CPE_VENDOR=	nlnetlabs
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs

USE_RC_SUBR=	routinator

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

.include <bsd.port.options.mk>

.if ${ARCH} == i386
RUSTFLAGS+=	-C target-feature=+sse2
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/routinator
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/routinator
	${INSTALL_DATA} ${WRKSRC}/etc/routinator.conf.example \
		${STAGEDIR}${PREFIX}/etc/routinator/routinator.conf.example

.include <bsd.port.mk>
