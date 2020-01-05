# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multicat
PORTVERSION=	2.2
CATEGORIES=	net multimedia
MASTER_SITES=	https://get.videolan.org/multicat/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and efficient multicast and transport stream manipulation

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/bitstream/mpeg/ts.h:multimedia/bitstream

USES=		localbase tar:bzip2
ALL_TARGET=	${PORTNAME}

PORTDOCS=	AUTHORS Changelog NEWS README
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
