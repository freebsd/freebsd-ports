# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chironfs
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	FUSE based filesystem with replication at the filesystem level

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		fuse

PLIST_FILES=	bin/chironfs bin/chirctl man/man8/chironfs.8.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's, doc , ,' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's,-liconv,${ICONV_LIB},' ${WRKSRC}/src/Makefile.*

.include <bsd.port.mk>
