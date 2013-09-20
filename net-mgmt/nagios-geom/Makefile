# Created by: rea-fbsd@codelabs.ru
# $FreeBSD$

PORTNAME=	geom
PORTVERSION=	1.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://codelabs.ru/fbsd/distfiles/ \
		http://fbsd.inse.ru/distfiles/
PKGNAMEPREFIX=	nagios-
DISTNAME=	check_geom-${PORTVERSION}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Nagios plug-in to get geom(8) components status

USES=		perl5
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PATCH_STRIP=	-p1

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_geom ${PREFIX}/libexec/nagios

.include <bsd.port.mk>
