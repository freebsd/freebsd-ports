# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.asterisk.org/pub/telephony/asterisk/ \
		ftp://ftp.asterisk.org/pub/telephony/asterisk/old-releases/

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

ONLY_FOR_ARCHS=	i386

BUILD_DEPENDS=  ${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql40-client \
		${NONEXISTENT}:${PORTSDIR}/devel/pwlib:build \
		${NONEXISTENT}:${PORTSDIR}/net/openh323:build
LIB_DEPENDS=	speex.2:${PORTSDIR}/audio/speex
RUN_DEPENDS=    ${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql40-client

GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/editline
USE_GMAKE=	yes
USE_OPENLDAP=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${WRKDIR}/../../../devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIR}/../../../net/openh323/work/openh323 \
		OSVERSION=${OSVERSION} \
		CXX="${CXX}"

.include <bsd.port.mk>
