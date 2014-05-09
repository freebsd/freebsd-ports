# Created by: Kris Kennaway <kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	ctrace
PORTVERSION=	0.9
CATEGORIES=	net
MASTER_SITES=	http://www.pratyeka.org/ctrace/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprotocol traceroute tool

BUILD_DEPENDS=	p5-Net-RawIP>=0:${PORTSDIR}/net/p5-Net-RawIP
RUN_DEPENDS=	p5-Net-RawIP>=0:${PORTSDIR}/net/p5-Net-RawIP \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
USES=		perl5

PLIST_FILES=	sbin/ctrace man/man1/ctrace.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ctrace ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ctrace.man ${STAGEDIR}${PREFIX}/man/man1/ctrace.1

.include <bsd.port.mk>
