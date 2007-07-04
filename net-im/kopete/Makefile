# New ports collection makefile for:	kopete
# Date created:		Wed Apr 12 17:51:07 UTC 2006
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kopete
PORTVERSION=	0.12.5
CATEGORIES?=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/3.5.7/src
PKGNAMEPREFIX=	kdenetwork-
DISTNAME=	kdenetwork-3.5.7
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multi-protocol instant messenger (IM)

RUN_DEPENDS=	${QT_PREFIX}/lib/plugins/crypto/libqca-tls.so:${PORTSDIR}/security/qca-tls

CONFLICTS=	kdenetwork-[0-2]* kdenetwork-3.[0-4]* kdenetwork-3.5.[0-2]* kvirc-[0-9]*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_GNOME=	glib20
USE_OPENSSL=	yes

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ilbc=${LOCALBASE} \
		--with-speex=${LOCALBASE} \
		--with-ssl-dir=${OPENSSLBASE} \
		--without-external-libgadu
USE_LDCONFIG=	yes
_NO_KDE_FINAL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/kopete
INSTALL_WRKSRC=	${WRKSRC}/kopete

PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500028
CONFIGURE_ARGS+=--enable-jingle
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex \
		ilbc:${PORTSDIR}/net/ilbc \
		ortp:${PORTSDIR}/net/ortp
CONFIGURE_ENV+=	PKG_CONFIG="${PKG_CONFIG}" \
		EXPAT_CFLAGS="-I${LOCALBASE}/include" \
		EXPAT_LIBS="-L${LOCALBASE}/lib -lexpat" \
		ILBC_CFLAGS="-I${LOCALBASE}/include/ilbc" \
		ILBC_LIBS="-L${LOCALBASE}/lib -lilbc" \
		SPEEX_CFLAGS="$$(${PKG_CONFIG} --cflags speex)" \
		SPEEX_LIBS="$$(${PKG_CONFIG} --libs speex)"
.endif

post-patch:
# force usage of gthread for libjingle's benefit
	@${REINPLACE_CMD} -E \
		-e 's|(glib-2.0)|gthread-2.0 \1|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
.if ${OSVERSION} < 500028
	@${REINPLACE_CMD} -e 's|$$(depcomp)||g' \
		${WRKSRC}/kopete/protocols/jabber/libiris/iris/xmpp-core/Makefile
.endif
# configure does not handle OSS support
.for feature in \
	FEATURE_ENABLE_CHAT_ARCHIVING \
	FEATURE_ENABLE_SSL \
	HAVE_SYS_SOUNDCARD_H
	@${ECHO_CMD} \
		'#define ${feature} 1' >> \
		${CONFIGURE_WRKSRC}/config.h
.endfor

.include <bsd.port.post.mk>
