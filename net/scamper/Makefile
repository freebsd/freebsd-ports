PORTNAME=	scamper
DISTVERSION=	20211026
CATEGORIES=	net
MASTER_SITES=	https://www.caida.org/catalog/software/scamper/code/
DISTNAME=	${PORTNAME}-cvs-${PORTVERSION}

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	HOIHO UPTIME
OPTIONS_SUB=	yes

HOIHO_DESC=	Install sc_hoiho
UPTIME_DESC=	Install sc_uptime

HOIHO_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
HOIHO_USES=		localbase:ldflags
HOIHO_CONFIGURE_WITH=	pcre2 sc_hoiho

UPTIME_USES=		localbase:ldflags sqlite:3
UPTIME_CONFIGURE_WITH=	sc_uptime

.include <bsd.port.mk>
