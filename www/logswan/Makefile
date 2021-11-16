# Created by: Juraj Lutter <juraj@lutter.sk>

PORTNAME=	logswan
DISTVERSION=	2.1.11
CATEGORIES=	www
MASTER_SITES=	https://github.com/fcambus/logswan/releases/download/${DISTVERSION}/

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Fast Web log analyzer

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libmaxminddb.so:net/libmaxminddb

USES=		cmake compiler:c11

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
