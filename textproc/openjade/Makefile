# Created by: kuriyama
# $FreeBSD$

PORTNAME=	openjade
PORTVERSION=	1.3.3p1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.3.3
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/-pre/}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine

LIB_DEPENDS=	libosp.so:textproc/opensp
RUN_DEPENDS=	${XMLCATMGR}:textproc/xmlcatmgr

USES=		gettext gmake libtool perl5
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${DATADIR}
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install install-man
MAKE_ENV=	STRIP="${STRIP}"
PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

DATADIR=	${PREFIX}/share/sgml/openjade

post-patch:
	@${REINPLACE_CMD} -e 's|<iostream.h>|<iostream>|' ${WRKSRC}/style/MultiLineInlineNote.cxx

post-install:
	@${FIND} ${WRKSRC}/dsssl -type f -depth 1 -exec ${INSTALL_DATA} {} ${STAGEDIR}/${DATADIR} \;

.include <bsd.port.mk>
