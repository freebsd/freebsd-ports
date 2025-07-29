PORTNAME=	scamper
DISTVERSION=	20250729
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
INSTALL_TARGET=	install-strip

SLAVE_PORT?=	no

.if ${SLAVE_PORT} == no

OPTIONS_DEFINE=	HOIHO MINRTT SUID_SCAMPER UPTIME
OPTIONS_SUB=	yes

HOIHO_DESC=		Install sc_hoiho
MINRTT_DESC=		Install sc_minrtt
SUID_SCAMPER_DESC=	Install scamper with setuid bit to allow non-root use
UPTIME_DESC=		Install sc_uptime

HOIHO_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
HOIHO_USES=		localbase:ldflags
HOIHO_CONFIGURE_ENABLE=	sc_hoiho
HOIHO_CONFIGURE_WITH=	pcre2

MINRTT_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
MINRTT_USES=		localbase:ldflags sqlite:3
MINRTT_CONFIGURE_ENABLE=	sc_minrtt
MINRTT_CONFIGURE_WITH=	pcre2

UPTIME_USES=		localbase:ldflags sqlite:3
UPTIME_CONFIGURE_ENABLE=	sc_uptime

.endif # ${SLAVE_PORT} == no

.include <bsd.port.mk>
