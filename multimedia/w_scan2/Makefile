# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	w_scan2
PORTVERSION=	1.0.11
CATEGORIES=	multimedia

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Perform frequency scans for DVB and ATSC transmissions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat

GNU_CONFIGURE=	yes
USES=		autoreconf gettext iconv localbase
LDFLAGS+=	${ICONV_LIB}

USE_GITHUB=	yes
GH_ACCOUNT=	stefantalpalaru

PORTDOCS=	COPYING ChangeLog README.md
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
