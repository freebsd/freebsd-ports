PORTNAME=	netevent
DISTVERSION=	0.2.1-79
PORTREVISION=	3
DISTVERSIONSUFFIX=	-g37c47a4
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for sharing uinput devices with other machines
WWW=		https://github.com/Blub/netevent

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		compiler:c++14-lang gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	Blub
HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		EXAMPLES MANPAGES
OPTIONS_DEFAULT=	EXAMPLES MANPAGES
OPTIONS_SUB=		MANPAGES

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_CONFIGURE_OFF=	--disable-doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/simple.ne2 ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
