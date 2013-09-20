# Created by: Felippe de Meirelles Motta <lippe@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	weathermap
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://netmon.grnet.gr/weathermap/dist/

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	This tool displays the utilization of the network links

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		mrtg:${PORTSDIR}/net-mgmt/mrtg

USES=		perl5
NO_BUILD=	yes

OPTIONS_DEFINE=	WGET
WGET_DESC=	WGET support

PORTDOCS=	README LICENSE INSTALL

CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MWGET}
RUN_DEPENDS+=	wget:${PORTSDIR}/ftp/wget
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		-e 's|weathermap.conf|${PREFIX}/etc/weathermap.conf|g' \
		${WRKSRC}/weathermap

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/weathermap ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/etc/weathermap
	@${INSTALL_DATA} ${WRKSRC}/example/* ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example/weathermap.conf ${PREFIX}/etc/weathermap/weathermap.sample.conf
	@[ -f ${PREFIX}/etc/weathermap/weathermap.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/example/weathermap.conf ${PREFIX}/etc/weathermap/weathermap.conf
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
