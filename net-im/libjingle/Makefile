# New ports collection makefile for:	libjingle
# Date created:		Wed Feb 22 01:33:20 UTC 2006
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libjingle
PORTVERSION=	0.3.0
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Google Talk's implementation of Jingle and Jingle-Audio

BUILD_DEPENDS=	\
		pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	\
		speex.3:${PORTSDIR}/audio/speex \
		ilbc.0:${PORTSDIR}/net/ilbc \
		ortp.4:${PORTSDIR}/net/ortp \
		expat.6:${PORTSDIR}/textproc/expat2

USE_GNOME=	glib20
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool:15
USE_DOS2UNIX=	README
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= \
		--with-ilbc=${LOCALBASE} \
		--with-speex=${LOCALBASE}
CONFIGURE_ENV=	\
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${OPENSSLINC} ${PTHREAD_CFLAGS} -g" \
		PKG_CONFIG="${PKG_CONFIG}" \
		EXPAT_CFLAGS="-I${LOCALBASE}/include" \
		EXPAT_LIBS="-L${LOCALBASE}/lib -lexpat" \
		GLIB_CFLAGS="$$(${PKG_CONFIG} --cflags glib-2.0)" \
		GLIB_LIBS="$$(${PKG_CONFIG} --libs glib-2.0)" \
		ILBC_CFLAGS="-I${LOCALBASE}/include/ilbc" \
		ILBC_LIBS="-L${LOCALBASE}/lib -lilbc" \
		SPEEX_CFLAGS="$$(${PKG_CONFIG} --cflags speex)" \
		SPEEX_LIBS="$$(${PKG_CONFIG} --libs speex)"

DOC_FILES=	\
		AUTHORS \
		ChangeLog \
		DOCUMENTATION \
		NEWS \
		README

.ifndef(NOPORTDOCS)
PORTDOCS=	\
		${DOC_FILES}
.endif

PLIST_FILES+=	\
		bin/relayserver \
		bin/stunserver \

post-configure:
# force glib
# force ilbc
# force speex
	@${REINPLACE_CMD} -E \
		-e 's|^.+(HAVE_GLIB)[[:space:]].*$$|#define \1 1|' \
		-e 's|^.+(HAVE_ILBC_DECODE_H)[[:space:]].*$$|#define \1 1|' \
		-e 's|^.+(HAVE_ILBC)[[:space:]].*$$|#define \1 1|' \
		-e 's|^.+(HAVE_SPEEX_H)[[:space:]].*$$|#define \1 1|' \
		-e 's|^.+(HAVE_SPEEX)[[:space:]].*$$|#define \1 1|' \
		${CONFIGURE_WRKSRC}/config.h
# configure does not handle OSS support
# force oss
# force ssl
.for feature in \
	FEATURE_ENABLE_SSL \
	HAVE_SYS_SOUNDCARD_H
	@${ECHO_CMD} \
		'#define ${feature} 1' >> \
		${CONFIGURE_WRKSRC}/config.h
.endfor

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

LDFLAGS+=-L${LOCALBASE}/lib -L${OPENSSLLIB} ${PTHREAD_LIBS}
PKG_CONFIG?=${LOCALBASE}/bin/pkg-config

.include <bsd.port.post.mk>
