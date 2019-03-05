# Created by: Robert Nelson <robertn@the-nelsons.org>
# $FreeBSD$

PORTNAME=	emailrelay
PORTVERSION=	1.9
PORTREVISION=	4
CATEGORIES=	mail ipv6
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	robertn@the-nelsons.org
COMMENT=	Simple SMTP proxy and store-and-forward MTA

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	e_spooldir=${PREFIX}/var/spool/emailrelay
CONFIGURE_ARGS=	--without-pam
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=		DOCS DOXYGEN GUI OPENSSL IPV6
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SUB=		yes

DOXYGEN_CONFIGURE_WITH=	doxygen
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

GUI_CONFIGURE_ENABLE=	gui
GUI_CONFIGURE_ENV=	e_qtmoc="${MOC}"
GUI_USES=		qt:4
GUI_USE=		QT=gui,moc

OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_USES=		ssl
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}

IPV6_CONFIGURE_ENABLE=	ipv6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/emailrelay.auth.template \
		${STAGEDIR}${PREFIX}/etc/emailrelay.auth.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/emailrelay.conf.template \
		${STAGEDIR}${PREFIX}/etc/emailrelay.conf.sample
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/emailrelay/init

.include <bsd.port.mk>
