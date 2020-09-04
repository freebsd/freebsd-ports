# Created by: walt
# $FreeBSD$

PORTNAME=	monitord
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://lissyara.su/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Service that restarts other standalone services

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_RC_SUBR=	monitord

post-install:
	${INSTALL_DATA} ${WRKSRC}/monitord.conf.sample \
		${STAGEDIR}${PREFIX}/etc/monitord.conf.sample

.include <bsd.port.mk>
