# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_clamav
PORTVERSION=	0.23
PORTREVISION=	4
CATEGORIES=	www security
MASTER_SITES=	http://software.othello.ch/mod_clamav/ \
		http://www.kommunity.net/download/mod_clamav/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	tmueko@kommunity.net
COMMENT=	Scans content delivered by the Apache20 proxy module for viruses


USE_AUTOTOOLS=	libtool
USE_APACHE=	22
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		CLAMAVDEVEL
CLAMAVDEVEL_DESC=	development version of CLAMAV

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLAMAVDEVEL}
LIB_DEPENDS+=	clamav.7:${PORTSDIR}/security/clamav-devel
.else
CLAMAV_PORT=	security/clamav
LIB_DEPENDS+=	clamav.7:${PORTSDIR}/security/clamav
.endif

CONFIGURE_ARGS=	--with-apxs=${APXS} \
		--libdir=${PREFIX}/lib/apache2
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib \
		-pthread

post-patch:
	@${REINPLACE_CMD} -e 's,REG_EXTENDED,AP_REG_EXTENDED,' \
		${WRKSRC}/config.c
	@${REINPLACE_CMD} -e '/^AC_CHECK_HEADERS/ s,regex.h ,,g' \
		${WRKSRC}/configure.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
