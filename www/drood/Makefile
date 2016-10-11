# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	drood
PORTVERSION=	5.37
CATEGORIES=	www
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Lightweight kqueue-based http/1.1 server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl

MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		MKDIR="${MKDIR}"

PLIST_FILES=	bin/drood \
		man/man8/drood.8.gz \
		man/man8/droodpipe.8.gz \
		etc/rc.d/drood \
		etc/drood/types.tab \
		etc/drood/types.tab.dist

.include <bsd.port.mk>
