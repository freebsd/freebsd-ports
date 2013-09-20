# Created by: Michael L. Hostbaek <mich@freebsdcluster.org>
# $FreeBSD$

PORTNAME=	wping
PORTVERSION=	0.1a
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://freebsdcluster.org/~mich/software/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A Web-based graphical ping log

RUN_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

USES=		perl5
USE_BZIP2=	yes
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/wping.pl ${PREFIX}/bin/wping
		${INSTALL_DATA} ${WRKSRC}/wping.conf ${PREFIX}/etc/wping.conf.sample

.include <bsd.port.mk>
