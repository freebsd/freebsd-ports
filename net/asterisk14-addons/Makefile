# Created by: Fabian Gast <fgast@only640k.org>
# $FreeBSD$

PORTNAME=	asterisk14
PORTVERSION=	1.4.13
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
PKGNAMESUFFIX=	-addons
DISTNAME=	asterisk${PKGNAMESUFFIX}-${DISTVERSION}

MAINTAINER=	bamby@sippysoft.com
COMMENT=	GPL modules for the Asterisk Open Source PBX

DEPRECATED=	Depends on broken and unsupported asterisk14
EXPIRATION_DATE=2014-04-30

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk14
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk14

OPTIONS_DEFINE=	SAMPLE_CONFIG
SAMPLE_CONFIG_DESC=	Install sample configuration files

ONLY_FOR_ARCHS=	i386 amd64 powerpc
USE_AUTOTOOLS=	libtool
USE_MYSQL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSAMPLE_CONFIG}
PLIST_SUB+=	SAMPLE_CONFIG=""
.else
PLIST_SUB+=	SAMPLE_CONFIG="@comment "
.endif

pre-configure:
	if ${GREP} -sq fixup_codecs ${LOCALBASE}/include/asterisk/channel.h; \
	then \
		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/codecnego.diff; \
	fi

post-install:
.if ${PORT_OPTIONS:MSAMPLE_CONFIG}
	@cd ${WRKSRC} && ${GMAKE} samples
.endif

.include <bsd.port.post.mk>
