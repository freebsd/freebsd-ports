PORTNAME=	passivedns
DISTVERSION=	1.2.1-25
DISTVERSIONSUFFIX=	-gb438a30
CATEGORIES=	security

MAINTAINER=	shadowbq@gmail.com
COMMENT=	Network sniffer that logs DNS replies for use in passive DNS setups

LICENSE=	GPLv2

LIB_DEPENDS=	libldns.so:dns/ldns

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_ACCOUNT=	gamelinux

USE_RC_SUBR=	passivedns

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldns-includes=${LOCALBASE}/include \
		--with-ldns-libraries=${LOCALBASE}/lib

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	JSON
OPTIONS_DEFAULT=	JSON

JSON_LIB_DEPENDS=	libjansson.so:devel/jansson
JSON_CONFIGURE_ENABLE=	json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/passivedns \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/var/log/passivedns

.include <bsd.port.mk>
