# $FreeBSD$

PORTNAME=	scanhill
DISTVERSION=	0.5-p1
PORTREVISION=	1
CATEGORIES=	security net-im
MASTER_SITES=	http://www.enderunix.org/scanhill/ \
		http://www.sourcefiles.org/Networking/Security/Sniffers/ \
		http://www.mirrorservice.org/sites/download.sourceforge.net/pub/sourceforge/s/sc/scanhill/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Microsoft Messenger Protocol Sniffer

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USES=		iconv

PORTDOCS=	README.txt INSTALL.txt mysql.sql

OPTIONS_DEFINE=	MYSQL DOCS

MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_ENABLE=	mysql

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' \
		-e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanhill ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/scanhill.conf ${STAGEDIR}${PREFIX}/etc/scanhill.conf-dist
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
