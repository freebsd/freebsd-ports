# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libjingle
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Google Talk's implementation of Jingle and Jingle-Audio

LIB_DEPENDS=	speex:${PORTSDIR}/audio/speex \
		ilbc:${PORTSDIR}/net/ilbc \
		ortp:${PORTSDIR}/net/linphone-base \
		expat:${PORTSDIR}/textproc/expat2

CONFLICTS=	krb4-[0-9]* krb5-[0-9]* heimdal-[0-9]* srp-[0-9]* \
		clusterit-[0-9]* pcp-[0-9]* synce-librapi2-[0-9]*

USE_GNOME=	glib20
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool
USE_DOS2UNIX=	README
USE_PKGCONFIG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ilbc=${LOCALBASE} \
		--with-speex=${LOCALBASE}
CONFIGURE_ENV=	PKG_CONFIG="${PKG_CONFIG}" \
		EXPAT_CFLAGS="-I${LOCALBASE}/include" \
		EXPAT_LIBS="-L${LOCALBASE}/lib -lexpat" \
		GLIB_CFLAGS="$$(${PKG_CONFIG} --cflags glib-2.0)" \
		GLIB_LIBS="$$(${PKG_CONFIG} --libs glib-2.0)" \
		ILBC_CFLAGS="-I${LOCALBASE}/include/ilbc" \
		ILBC_LIBS="-L${LOCALBASE}/lib -lilbc" \
		SPEEX_CFLAGS="$$(${PKG_CONFIG} --cflags speex)" \
		SPEEX_LIBS="$$(${PKG_CONFIG} --libs speex)"
CPPFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC} ${PTHREAD_CFLAGS} -g
MAKE_JOBS_SAFE=	yes
LDFLAGS+=-L${LOCALBASE}/lib -L${OPENSSLLIB} ${PTHREAD_LIBS}

PORTDOCS=	AUTHORS \
		ChangeLog \
		DOCUMENTATION \
		NEWS \
		README

PLIST_FILES+=	bin/login \
		bin/pcp \
		bin/relayserver \
		bin/stunserver \

.include <bsd.port.options.mk>

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
.for feature in \
	HAVE_SYS_SOUNDCARD_H
	@${ECHO_CMD} \
		'#define ${feature} 1' >> \
		${CONFIGURE_WRKSRC}/config.h
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
