# New ports collection makefile for:	tntnet
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tntnet
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	http://www.tntnet.org/download/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Webapplicationserver for C++

LIB_DEPENDS=	cxxtools:${PORTSDIR}/devel/cxxtools
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip

USE_ICONV=	yes
USE_CSTD=	gnu89
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=	--localstatedir=/var

.if defined(WITH_GNUTLS)
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lgnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.else
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-ssl=openssl
.endif

MAKE_JOBS_SAFE=	yes
MAN1=		ecppc.1 ecppl.1 ecppll.1 tntnet-config.1
MAN7=		ecpp.7 tntnet.conf.7 tntnet.properties.7
MAN8=		tntnet.8

USERS=		www
GROUPS=		www

post-configure:
	${REINPLACE_CMD} 's/^\(#define[[:space:]]*HAVE_SENDFILE[[:space:]]*\).*/\1\0/' ${WRKSRC}/framework/common/config.h

post-install:
	@if [ ! -f ${ETCDIR}/tntnet.conf ]; then \
	    ${CP} -p ${ETCDIR}/tntnet.conf.sample ${ETCDIR}/tntnet.conf ; \
	fi
	@if [ ! -f ${ETCDIR}/mime.conf ]; then \
	    ${CP} -p ${ETCDIR}/mime.conf.sample ${ETCDIR}/mime.conf ; \
	fi
	@if [ ! -f ${ETCDIR}/tntnet.properties ]; then \
	    ${CP} -p ${ETCDIR}/tntnet.properties.sample ${ETCDIR}/tntnet.properties ; \
	fi

.include <bsd.port.mk>
