# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	doscan
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://static.enyo.de/fw/releases/doscan/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to quickly scan your network for machines listening on a TCP port

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
USES=		gmake

PORTDOCS=	README
PLIST_FILES=	bin/doscan man/man1/doscan.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|ony o|on yo|' \
		${WRKSRC}/doc/doscan.1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
