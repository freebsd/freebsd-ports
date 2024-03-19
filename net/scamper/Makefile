PORTNAME=	scamper
DISTVERSION=	20240229
CATEGORIES=	net
MASTER_SITES=	https://www.caida.org/catalog/software/scamper/code/
DISTNAME=	${PORTNAME}-cvs-${DISTVERSION}

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement
WWW=		https://www.caida.org/tools/measurement/scamper/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		gmake libtool ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

SLAVE_PORT?=	no

.if ${SLAVE_PORT} == no

OPTIONS_DEFINE=	HOIHO UPTIME
OPTIONS_SUB=	yes

HOIHO_DESC=	Install sc_hoiho
UPTIME_DESC=	Install sc_uptime

HOIHO_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
HOIHO_USES=		localbase:ldflags
HOIHO_CONFIGURE_ENABLE=	sc_hoiho
HOIHO_CONFIGURE_WITH=	pcre2

UPTIME_USES=		localbase:ldflags sqlite:3
UPTIME_CONFIGURE_ENABLE=	sc_uptime

.endif # ${SLAVE_PORT} == no

.include <bsd.port.mk>
