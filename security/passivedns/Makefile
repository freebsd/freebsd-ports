# $FreeBSD$

PORTNAME=	passivedns
DISTVERSION=	1.2.1-10
DISTVERSIONSUFFIX=	-ge126cbb
CATEGORIES=	security

MAINTAINER=	shadowbq@gmail.com
COMMENT=	Network sniffer that logs DNS replies for use in passive DNS setups

LICENSE=	GPLv2

LIB_DEPENDS=	libldns.so:dns/ldns

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_ACCOUNT=	gamelinux

SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldns-includes=${LOCALBASE}/include \
		--with-ldns-libraries=${LOCALBASE}/lib

USE_RC_SUBR=	passivedns

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/passivedns \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/var/log/passivedns

.include <bsd.port.mk>
