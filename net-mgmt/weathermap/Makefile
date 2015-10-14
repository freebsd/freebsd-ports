# Created by: Felippe de Meirelles Motta <lippe@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	weathermap
PORTVERSION=	1.1.1
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	http://netmon.grnet.gr/weathermap/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This tool displays the utilization of the network links

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		mrtg:${PORTSDIR}/net-mgmt/mrtg

USES=		perl5 shebangfix
NO_BUILD=	yes
SHEBANG_FILES=	weathermap

OPTIONS_DEFINE=	WGET DOCS EXAMPLES
WGET_DESC=	WGET support

PORTDOCS=	README LICENSE INSTALL

CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWGET}
RUN_DEPENDS+=	wget:${PORTSDIR}/ftp/wget
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		-e 's|weathermap.conf|${PREFIX}/etc/weathermap.conf|g' \
		${WRKSRC}/weathermap

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/weathermap ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/example/* ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example/weathermap.conf ${STAGEDIR}${ETCDIR}/weathermap.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
