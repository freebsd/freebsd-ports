# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	1.0.9
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.asterisk.org/pub/telephony/asterisk/ \
		ftp://ftp.asterisk.org/pub/telephony/asterisk/old-releases/

PATCHFILES=	${PORTNAME}-1.0.8-${BRIVER}.patch.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	fjoe
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	speex.3:${PORTSDIR}/audio/speex \
		newt.51:${PORTSDIR}/devel/newt
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 sparc64

BRIVER=		bristuff-0.2.0-RC8h
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/editline
USE_GMAKE=	yes
USE_BISON=	yes
USE_RC_SUBR=	asterisk.sh
USE_REINPLACE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${WRKDIRPREFIX}${PORTSDIR}/devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${PORTSDIR}/net/openh323/work/openh323 \
		OSVERSION=${OSVERSION} \
		CXX="${CXX}"

MAN8=		asterisk.8

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_H323=	1
WITHOUT_ZAPTEL=	1
.endif

.if defined(WITHOUT_H323)
PLIST_SUB+=	WITH_H323="@comment "
.else
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/devel/pwlib:build \
		${NONEXISTENT}:${PORTSDIR}/net/openh323:build
PLIST_SUB+=	WITH_H323=""
MAKE_ENV+=	WITH_H323=1
.endif

.if defined(WITHOUT_ZAPTEL)
PLIST_SUB+=	WITH_ZAPTEL="@comment "
.else
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
BUILD_DEPENDS+=	${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
RUN_DEPENDS+=	${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
PLIST_SUB+=	WITH_ZAPTEL=""
MAKE_ENV+=	WITH_ZAPTEL=1
.endif

#
# WITH_FREETDS, WITH_PGSQL and WITH_SQLITE can also be added to MAKE_ENV
# similarly
.if defined(WITHOUT_ODBC)
PLIST_SUB+=	WITH_ODBC="@comment "
.else
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
PLIST_SUB+=	WITH_ODBC=""
MAKE_ENV+=	WITH_ODBC=1
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
.endif

#
# FAX apps can't be compiled on RELENG_4 at the moment
.if defined(WITHOUT_FAX) || ${OSVERSION} < 500000
PLIST_SUB+=	WITH_FAX="@comment "
.else
MAKE_ENV+=	WITH_FAX=1
LIB_DEPENDS+=	spandsp.0:${PORTSDIR}/comms/spandsp
PLIST_SUB+=	WITH_FAX=""
.endif

post-patch:
	${CP} ${FILESDIR}/chan_oss.c ${WRKSRC}/channels
	${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample

.include <bsd.port.post.mk>
