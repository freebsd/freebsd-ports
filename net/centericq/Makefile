# ex:ts=8
# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	4.9.10
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://centericq.de/archive/source/releases/

MAINTAINER=	clsung@dragon2.net
COMMENT=	A text mode menu- and window-driven IM interface

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib -lstdc++
CONFIGURE_ARGS=	--with-openssl --disable-konst

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

.if defined(WITH_MSN)
CONFIGURE_ARGS+=	--enable-msn
EXTRA_PATCHES=		${.CURDIR}/files/msn-*
pre-patch:
	@${ECHO_CMD} "========================================================="
	@${ECHO_CMD} "=====================Important !!!======================="
	@${ECHO_CMD} "========================================================="
	@${ECHO_CMD} "There may be some sticky legal issues with the new"
	@${ECHO_CMD} "version of this protocol. Users should be aware that they"
	@${ECHO_CMD} "might be in violation of the DMCA or other laws. If this"
	@${ECHO_CMD} "is unacceptable, hit Ctrl-C now and remove WITH_MSN from"
	@${ECHO_CMD} "your make flags. The FreeBSD group assumes no"
	@${ECHO_CMD} "responsibility or liability for any losses or damages"
	@${ECHO_CMD} "sustained by use or disuse of software in the ports tree."
	@${ECHO_CMD} "========================================================="
	@sleep 5
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
