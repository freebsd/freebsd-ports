PORTNAME=	trippy
DISTVERSION=	0.10.0
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Network diagnostic tool inspired by mtr
WWW=		https://github.com/fujiapple852/trippy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	fujiapple852

PORTSCOUT=	skipv:1.0.0

OPTIONS_DEFINE=		MANPAGES SUID
OPTIONS_DEFAULT=	MANPAGES SUID
OPTIONS_SUB=		yes

MANPAGES_DESC=	Build and install auto-generated manpages
SUID_DESC=	Use suid to allow execution as non root

MANPAGES_BUILD_DEPENDS=	help2man:misc/help2man
MANPAGES_PLIST_FILES=	share/man/man1/trip.1.gz
SUID_PLIST_FILES=	"@(,,4110) bin/trip"
SUID_PLIST_FILES_OFF=	"@(,,0100) bin/trip"

post-build-MANPAGES-on:
	help2man -s 1 -Nn "${COMMENT}" \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/trip \
		-o ${WRKSRC}/trip.1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/trip

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/trip.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
