# New ports collection makefile for:	mod_clamav
# Date created:				Sun Oct 19
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_clamav
PORTVERSION=	0.23
PORTREVISION=	3
CATEGORIES=	www security
MASTER_SITES=	http://software.othello.ch/mod_clamav/ \
		http://www.kommunity.net/download/mod_clamav/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	tmueko@kommunity.net
COMMENT=	Scans content delivered by the Apache20 proxy module for viruses

MAKE_JOBS_SAFE=  yes

USE_AUTOTOOLS=	libtool:22
USE_APACHE=	2.2
GNU_CONFIGURE=	yes

.if defined(WITH_CLAMAVDEVEL)
LIB_DEPENDS+=	clamav.7:${PORTSDIR}/security/clamav-devel
.else
CLAMAV_PORT=	security/clamav
LIB_DEPENDS+=	clamav.7:${PORTSDIR}/security/clamav
.endif

CONFIGURE_ARGS=	--with-apxs=${APXS} \
		--libdir=${PREFIX}/lib/apache2
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib \
		${PTHREAD_LIBS}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's,REG_EXTENDED,AP_REG_EXTENDED,' \
		${WRKSRC}/config.c
	@${REINPLACE_CMD} -e '/^AC_CHECK_HEADERS/ s,regex.h ,,g' \
		${WRKSRC}/configure.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
