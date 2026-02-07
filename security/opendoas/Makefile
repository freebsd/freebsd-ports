PORTNAME=	opendoas
DISTVERSIONPREFIX=	v
DISTVERSION=	6.8.2
CATEGORIES=	security

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# pam: always print pam_conv messages to stderr:
# https://github.com/Duncaen/OpenDoas/issues/95
PATCHFILES+=	b96106b7e34ac591ae78b1684e9be3a265122463.patch:-p1
# Added freebsd support for timestamp (persist):
# https://github.com/Duncaen/OpenDoas/pull/127
PATCHFILES+=	97218322213274eb24ab633e09478075b2282ab3.patch:-p1

MAINTAINER=	fierceinbattle@gmail.com
COMMENT=	Port of OpenDoas: a portable version of OpenBSD's doas
WWW=		https://github.com/Duncaen/OpenDoas

LICENSE=	OPENDOAS
LICENSE_NAME=	OPENDOAS
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Duncaen
GH_PROJECT=	OpenDoas

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-timestamp \
		--without-shadow

MAKEFILE=	GNUmakefile

CONFLICTS=	doas

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/doas

.include <bsd.port.mk>
