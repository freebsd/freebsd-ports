# Created by: Joe Barbish <ppars1@a1poweruser.com>
# $FreeBSD$

PORTNAME=	ppars
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ppars1@a1poweruser.com
COMMENT=	Proactive Probing Abuse Reporting System

RUN_DEPENDS=	p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask

USES=		perl5 shebangfix tar:bzip2
NO_BUILD=	yes

SHEBANG_FILES=	*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
