# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_clamav
PORTVERSION=	0.23
PORTREVISION=	6
CATEGORIES=	www security
MASTER_SITES=	http://software.othello.ch/mod_clamav/ \
		http://www.kommunity.net/download/mod_clamav/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	tmueko@kommunity.net
COMMENT=	Scans content delivered by the Apache20 proxy module for viruses

LICENSE=	GPLv2

USE_APACHE=	22
USES=		libtool
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

CLAMAV_PORT=	security/clamav
LIB_DEPENDS+=	libclamav.so:security/clamav

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

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	$(APXS) -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} \
		-i -n 'clamav' ${WRKSRC}/.libs/mod_clamav.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so

.include <bsd.port.mk>
