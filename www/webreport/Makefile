# Created by: ismail@enderunix.org
# $FreeBSD$

PORTNAME=	webreport
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.inter7.com/webreport/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	WebReport is a web log statistics program  for web hosting sites

BROKEN=		unfetchable

SUB_FILES=	pkg-message
PORTDOCS=	INSTALL
PLIST_FILES=	bin/webreport etc/webreport.conf-dist

# silence clang errors on 10.0+
CFLAGS+=	-Wno-return-type

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,ulong,unsigned long,;s,/etc/,${PREFIX}/etc/,' ${WRKSRC}/webreport.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webreport ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/webreport.conf ${STAGEDIR}${PREFIX}/etc/webreport.conf-dist

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
