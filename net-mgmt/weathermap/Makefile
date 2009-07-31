# New ports collection makefile for:	weathermap
# Date created:		2007-05-03
# Whom:			Felippe de Meirelles Motta <lippe@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	weathermap
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://netmon.grnet.gr/weathermap/dist/

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	This tool displays the utilization of the network links

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/GD/Image.pm:${PORTSDIR}/graphics/p5-GD \
		mrtg:${PORTSDIR}/net-mgmt/mrtg

NO_BUILD=	yes
USE_PERL5=	yes

OPTIONS=	WGET "Enable WGET support" OFF

PORTDOCS=	README LICENSE INSTALL

CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_WGET)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
