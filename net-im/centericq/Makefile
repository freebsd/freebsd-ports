# ex:ts=8
# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	4.21.0
PORTREVISION=	11
CATEGORIES=	net-im
MASTER_SITES=	http://thekonst.net/download/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A text mode menu- and window-driven IM interface

USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="-I${LOCALBASE}/include ${CXXFLAGS}"
LDFLAGS+=	-L${LOCALBASE}/lib -lstdc++
CONFIGURE_ARGS=	--with-openssl --disable-konst

OPTIONS=	NLS		"Native Language Support" on \
		MULTIBYTE	"Multibyte Support" off \
		FRIBIDI		"Fribidi Support" off \
		MSN		"Support for MSN Protocol" off \
		YAHOO		"Support for Yahoo! Messenger Protocol" off \
		AIM		"Support for AOL's Instant Messenger Protocol" off \
		IRC		"Support for IRC Protocol" off \
		JABBER		"Support for Jabber Protocol" off \
		GPGME		"Support for PGP encrypted Jabber messages" on \
		RSS		"Support for RSS" off \
		LJ		"Support for LiveJournal" off \
		GG		"Support for Gadu-Gadu Protocol" off

MAN1=	cicqconv.1 cicqsync.1

PORTDOCS=	FAQ README

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
# Don't use optimization since it sefgaults in some cases otherwise.
CFLAGS:=	${CFLAGS:C/-O[0123456789]*/-O0/}
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif

.if defined(WITH_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=	--with-fribidi
.endif

.if !defined(WITH_MSN)
CONFIGURE_ARGS+=	--disable-msn
.else
LIB_DEPENDS+=		curl.5:${PORTSDIR}/ftp/curl
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
.else
.if !defined(WITH_GPGME)
CONFIGURE_ARGS+=	--without-gpgme
.else
LIB_DEPENDS+=		gpgme.18:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--with-gpgme=${LOCALBASE}
.endif
.endif

.if !defined(WITH_RSS)
CONFIGURE_ARGS+=	--disable-rss
.endif

.if !defined(WITH_LJ)
CONFIGURE_ARGS+=	--disable-lj
.endif

.if !defined(WITH_GG)
CONFIGURE_ARGS+=	--disable-gg
.else
LIB_DEPENDS+=	gadu.3:${PORTSDIR}/polish/ekg
LIBGADU=	-lgadu
.endif

post-patch:
.for file in kkconsui-0.1/include/conf.h kkstrtext-0.1/conf.h kksystr-0.1/include/conf.h
	@(cd ${WRKSRC} ; \
	  ${MV} -f ${file} ${file}.orig ; \
	  ${GREP} -v "_G_config.h" ${file}.orig > ${file})
.endfor
	@${FIND} ${WRKSRC} -name "Makefile*" -type f -print0 | \
		${XARGS} -0 \
	        ${REINPLACE_CMD} -E \
		-e "s|-I\$$\(top_srcdir\)/libgadu-0.1|-I${LOCALBASE}/include|" \
		-e "s|-L\$$\(top_srcdir\)/libgadu-0.1|-L${LOCALBASE}/lib|" \
		-e 's|libgadu-0.1/*||' \
		-e 's|libgadu-0.1||' \
		-e 's|-llibgadu|${LIBGADU}|'

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
