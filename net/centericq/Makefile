# ex:ts=8
# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	4.9.11
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://centericq.de/archive/source/releases/

MAINTAINER=	clsung@dragon2.net
COMMENT=	A text mode menu- and window-driven IM interface

USE_ICONV=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib -lstdc++
CONFIGURE_ARGS=	--with-openssl --disable-konst

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-locales-fix
.else
pre-fetch:
	@${ECHO_CMD} "Type \"make WITH_MULTIBYTE=yes\" if you want multibyte support."
.endif

.if defined(WITH_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=	--with-fribidi
.endif

.if !defined(WITH_MSN)
CONFIGURE_ARGS+=	--disable-msn
.endif

.if !defined(WITH_YAHOO)
CONFIGURE_ARGS+=	--disable-yahoo
.endif

.if !defined(WITH_AIM)
CONFIGURE_ARGS+=	--disable-aim
.endif

.if !defined(WITH_IRC)
CONFIGURE_ARGS+=	--disable-irc
.endif

.if !defined(WITH_JABBER)
CONFIGURE_ARGS+=	--disable-jabber
.endif

.if !defined(WITH_RSS)
CONFIGURE_ARGS+=	--disable-rss
.endif

.if !defined(WITH_LJ)
CONFIGURE_ARGS+=	--disable-lj
.endif

.if !defined(WITH_GG)
CONFIGURE_ARGS+=	--disable-gg
.endif

MAN1=	cicqconv.1 cicqsync.1

PORTDOCS=	FAQ README
post-patch:
.for file in kkconsui-0.1/include/conf.h kkstrtext-0.1/conf.h kksystr-0.1/include/conf.h
	@(cd ${WRKSRC} ; \
	  ${MV} -f ${file} ${file}.orig ; \
	  ${GREP} -v "_G_config.h" ${file}.orig > ${file})
.endfor

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
