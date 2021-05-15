PORTNAME=	inxi
DISTVERSION=	3.3.04-1
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Full featured CLI system information tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bind-tools>=0:dns/bind-tools \
		dmidecode:sysutils/dmidecode \
		mesa-demos>=0:graphics/mesa-demos \
		p5-Cpanel-JSON-XS>=0:converters/p5-Cpanel-JSON-XS \
		p5-HTTP-Tiny>=0:www/p5-HTTP-Tiny \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-XML-Dumper>=0:textproc/p5-XML-Dumper \
		tree:sysutils/tree \
		usbutils>=0:sysutils/usbutils \
		wmctrl:x11/wmctrl \
		xdpyinfo:x11/xdpyinfo \
		xprop:x11/xprop \
		xrandr:x11/xrandr

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	smxi
USE_PERL5=	run
SHEBANG_FILES=	${PORTNAME}

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	${PORTNAME}.changelog README.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
