PORTNAME=	openpgp-card-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.13
CATEGORIES=	security
MASTER_SITES=	https://codeberg.org/openpgp-card/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
# XXX Teach USES=cargo to not override default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	christian@hofstede.de
COMMENT=	CLI tool for interacting with OpenPGP cards
WWW=		https://codeberg.org/openpgp-card/openpgp-card-tools

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSES/Apache-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		cargo pkgconfig

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README.md scripting.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/oct

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	OCT_MANPAGE_OUTPUT_DIR=${WRKSRC}/man/man1 ${STAGEDIR}${PREFIX}/bin/oct
	${INSTALL_MAN} ${WRKSRC}/man/man1/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
