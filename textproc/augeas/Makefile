PORTNAME=	augeas
DISTVERSION=	1.14.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/hercules-team/augeas/releases/download/release-${DISTVERSION}/

PATCH_SITES=	https://github.com/hercules-team/augeas/commit/
PATCHFILES+=	7b26cbb74ed634d886ed842e3d5495361d8fd9b1.patch:-p1 # https://github.com/hercules-team/augeas/pull/792

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Configuration editing tool
WWW=		https://augeas.net/

LICENSE=	LGPL21

TEST_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed

USES=		autoreconf cpe gmake gnome libtool pathfix pkgconfig readline
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

LENSESDIR=	${PREFIX}/share/augeas/lenses

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:/bin/bash:/usr/bin/env bash:' ${WRKSRC}/tests/*.sh
	@${REINPLACE_CMD} -e 's:sed:gsed:' ${WRKSRC}/tests/test-augtool.sh
	@${REINPLACE_CMD} -e 's:/usr/local:${LOCALBASE}:' \
		${WRKSRC}/lenses/puppet.aug \
		${WRKSRC}/lenses/puppet_auth.aug \
		${WRKSRC}/lenses/puppetfileserver.aug

.include <bsd.port.post.mk>
