# Created by: kuriyama
# $FreeBSD$

PORTNAME=	OpenSP
PORTVERSION=	1.5.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/openjade/${PORTNAME:tl}/${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Collection of SGML/XML tools

LICENSE=	JamesClark
LICENSE_NAME=	License of James Clark's Software
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake iconv libtool localbase perl5
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${PREFIX}/share/sgml/openjade \
		--disable-doc-build

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

PORTDOCS=	*.htm NEWS AUTHORS README ABOUT-NLS BUGS ChangeLog

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS:N\*.htm} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
