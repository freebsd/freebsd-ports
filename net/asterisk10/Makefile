# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	1.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.asterisk.org/pub/telephony/asterisk/ \
		ftp://ftp.asterisk.org/pub/telephony/asterisk/old-releases/

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

ONLY_FOR_ARCHS=	i386 sparc64

BUILD_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql40-client
LIB_DEPENDS=	speex.3:${PORTSDIR}/audio/speex
RUN_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql40-client

GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/editline
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${WRKDIRPREFIX}${PORTSDIR}/devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${PORTSDIR}/net/openh323/work/openh323 \
		OSVERSION=${OSVERSION} \
		CXX="${CXX}"

MAN8=		asterisk.8

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} != "i386"
WITHOUT_H323=	1
WITHOUT_ZAPTEL=	1
.endif

.if defined(WITHOUT_H323)
MAKE_ENV+=	WITHOUT_H323=1
PLIST_SUB+=	WITH_H323="@comment "
.else
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/devel/pwlib:build \
		${NONEXISTENT}:${PORTSDIR}/net/openh323:build
PLIST_SUB+=	WITH_H323=""
.endif

.if defined(WITHOUT_ZAPTEL)
MAKE_ENV+=	WITHOUT_ZAPTEL=1
PLIST_SUB+=     WITH_ZAPTEL="@comment "
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
RUN_DEPENDS+=	${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
PLIST_SUB+=	WITH_ZAPTEL=""
.endif

.include <bsd.port.post.mk>
