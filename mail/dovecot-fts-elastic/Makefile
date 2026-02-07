PORTNAME=	fts-elastic
DISTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	mail
PKGNAMEPREFIX=	dovecot-

MAINTAINER=	bgupta@kde.org
COMMENT=	Dovecot FTS plugin for using ElasticSearch 6 or 7
WWW=		https://github.com/filiphanes/fts-elastic

LICENSE=	MIT

BUILD_DEPENDS=	dovecot>=2.3.7:mail/dovecot
LIB_DEPENDS=	libjson-c.so:devel/json-c
RUN_DEPENDS=	dovecot>=2.3.7:mail/dovecot

USES=		autoreconf libtool

USE_GITHUB=	yes
GH_ACCOUNT=	filiphanes

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=       -L${LOCALBASE}/lib
CPPFLAGS+=      -I${LOCALBASE}/include

PLIST_FILES=	lib/dovecot/lib21_fts_elastic_plugin.a \
		lib/dovecot/lib21_fts_elastic_plugin.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dovecot/lib21_fts_elastic_plugin.so

.include <bsd.port.mk>
