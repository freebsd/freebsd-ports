# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	1.2.13
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/

PKGNAMESUFFIX=	-bristuff
PATCHFILES=	${PORTNAME}-${PORTVERSION}-${BRIVER}.patch.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	fjoe
PATCH_DIST_STRIP=	-p1
BRIVER=		bristuff-0.3.0-PRE-1s
CONFLICTS=	asterisk-[0-9]*

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		newt.51:${PORTSDIR}/devel/newt \
		curl.5:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 sparc64 amd64

GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/editline
USE_GMAKE=	yes
USE_BISON=	build
USE_RC_SUBR=	asterisk.sh
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OSVERSION=${OSVERSION}
MAN8=		asterisk.8 astgenkey.8 autosupport.8 safe_asterisk.8

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_H323=	1
WITHOUT_ZAPTEL=	1
BROKEN=		current does not build
.endif

.if defined(WITHOUT_H323)
PLIST_SUB+=	WITH_H323="@comment "
.else
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib\
		h323_r.1:${PORTSDIR}/net/openh323
PLIST_SUB+=	WITH_H323=""
MAKE_ENV+=	WITH_H323=1
.endif

.if defined(WITHOUT_ZAPTEL)
PLIST_SUB+=	WITH_ZAPTEL="@comment "
MAKE_ENV+=	WITHOUT_ZAPTEL=1
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
LIB_DEPENDS+=	pri-bristuff.1:${PORTSDIR}/misc/libpri-bristuff
RUN_DEPENDS+=	${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
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

.if defined(WITHOUT_FAX)
PLIST_SUB+=	WITH_FAX="@comment "
.else
MAKE_ENV+=	WITH_FAX=1
LIB_DEPENDS+=	spandsp.0:${PORTSDIR}/comms/spandsp
PLIST_SUB+=	WITH_FAX=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample
	${REINPLACE_CMD} -e 's,^#include <libpri\.h>,#include <libpri-bristuff.h>,' ${WRKSRC}/channels/chan_zap.c

.include <bsd.port.post.mk>
