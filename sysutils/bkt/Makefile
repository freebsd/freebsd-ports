PORTNAME=	bkt
DISTVERSION=	0.8.2
PORTREVISION=	8
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Subprocess caching utility
WWW=		https://github.com/dimo414/bkt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	dimo414

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_DESC=		Build and install auto-generated manpages
MANPAGES_BUILD_DEPENDS=	help2man:misc/help2man

post-build-MANPAGES-on:
	help2man -s 1 -Nn "${COMMENT}" \
		${CARGO_TARGET_DIR}/*/${PORTNAME} \
		-o ${WRKSRC}/${PORTNAME}.1

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
