# Created by: Juraj Lutter <juraj@lutter.sk>
# $FreeBSD$

PORTNAME=	logswan
PORTVERSION=	2.1.4
CATEGORIES=	www

MAINTAINER=	juraj@lutter.sk
COMMENT=	Fast Web log analyzer

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libmaxminddb.so:net/libmaxminddb

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	fcambus

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
