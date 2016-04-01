# Created by: Felippe de Meirelles Motta <lippe@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	weathermap
PORTVERSION=	1.1.1
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	https://netmon.grnet.gr/weathermap/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This tool displays the utilization of the network links

BROKEN=		unfetchable
DEPRECATED=	Distfile unavailable, website no longer exists
EXPIRATION_DATE=2016-04-04

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgd.so:graphics/gd
RUN_DEPENDS=	p5-GD>=0:graphics/p5-GD \
		mrtg:net-mgmt/mrtg

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	weathermap

PORTSCOUT=	ignore:1

PORTDOCS=	README INSTALL

CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	WGET DOCS EXAMPLES
WGET_DESC=	WGET support
WGET_RUN_DEPENDS=	wget:ftp/wget

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		-e 's|weathermap.conf|${PREFIX}/etc/weathermap.conf|g' \
		${WRKSRC}/weathermap

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/weathermap ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/example/weathermap.conf ${STAGEDIR}${ETCDIR}/weathermap.conf.sample

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example/* ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
