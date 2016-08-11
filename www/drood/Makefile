# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	drood
PORTVERSION=	5.25
CATEGORIES=	www
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Lightweight kqueue-based http/1.1 server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libserver.so:devel/libserver

USE_LDCONFIG=	yes

USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}" \
		MKDIR="${MKDIR}"

PLIST_FILES=	bin/drood \
		bin/humdinger \
		lib/libdorrit.so \
		lib/libdorrit.so.${PORTVERSION} \
		include/dorrit.h \
		man/man8/drood.8.gz \
		man/man8/droodpipe.8.gz \
		man/man8/humdinger.8.gz \
		man/man8/libdorrit.8.gz \
		etc/rc.d/drood \
		"@(,,4550) etc/rc.d/humdinger" \
		etc/drood/types.tab \
		etc/drood/types.tab.dist

.include <bsd.port.mk>
