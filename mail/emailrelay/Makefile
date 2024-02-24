PORTNAME=	emailrelay
PORTVERSION=	1.9
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	robertn@the-nelsons.org
COMMENT=	Simple SMTP proxy and store-and-forward MTA
WWW=		https://emailrelay.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf pkgconfig
USE_CXXSTD=	c++14
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--without-pam
CONFIGURE_ENV=	e_spooldir=${PREFIX}/var/spool/emailrelay

OPTIONS_DEFINE=		DOCS DOXYGEN OPENSSL IPV6
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_WITH=	doxygen

IPV6_CONFIGURE_ENABLE=	ipv6

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/emailrelay.auth.template \
		${STAGEDIR}${PREFIX}/etc/emailrelay.auth.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/emailrelay.conf.template \
		${STAGEDIR}${PREFIX}/etc/emailrelay.conf.sample
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/emailrelay/init

.include <bsd.port.mk>
