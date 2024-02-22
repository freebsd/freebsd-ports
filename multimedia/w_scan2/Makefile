PORTNAME=	w_scan2
PORTVERSION=	1.0.15
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Perform frequency scans for DVB and ATSC transmissions
WWW=		https://github.com/stefantalpalaru/w_scan2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		autoreconf gettext iconv localbase
LDFLAGS+=	${ICONV_LIB}

USE_GITHUB=	yes
GH_ACCOUNT=	stefantalpalaru

PORTDOCS=	COPYING ChangeLog README.md
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
