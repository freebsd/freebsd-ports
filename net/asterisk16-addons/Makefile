# New ports collection makefile for:	asterisk-addons
# Date created:				23 March 2006
# Whom:					Fabian Gast <fgast@only640k.org>
#
# $FreeBSD$
#

PORTNAME=	asterisk16-addons
PORTVERSION=	1.6.0.2
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
DISTNAME=	asterisk-addons-${DISTVERSION}

MAINTAINER=	flo@kasimir.com
COMMENT=	GPL modules for the Asterisk Open Source PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk16
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk16

OPTIONS=	SAMPLE_CONFIG	"Install sample configuration files" off

ONLY_FOR_ARCHS=	i386 amd64 powerpc
USE_AUTOTOOLS=	libtool:15
USE_MYSQL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		OSVERSION=${OSVERSION} \
		NOISY_BUILD=YES \
		DOCSDIR=${DOCSDIR} \
		ASTCFLAGS="${CFLAGS}"

CONFLICTS=	asterisk*-1.2* asterisk*-1.4*

.include <bsd.port.pre.mk>

.if defined(WITH_SAMPLE_CONFIG)
PLIST_SUB+=	SAMPLE_CONFIG=""
.else
PLIST_SUB+=	SAMPLE_CONFIG="@comment "
.endif

#pre-configure:
#	if ${GREP} -sq fixup_codecs ${LOCALBASE}/include/asterisk/channel.h; \
#	then \
#		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/codecnego.diff; \
#	fi

post-install:
.if defined(WITH_SAMPLE_CONFIG)
	@cd ${WRKSRC} && ${GMAKE} samples
.endif

.include <bsd.port.post.mk>
