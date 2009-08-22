# ex:ts=8
# New ports collection makefile for:           centerim
# Date created:                                2006-03-14
# Whom:                                 Frank Altpeter <frank@altpeter.de>
#
# $FreeBSD$
#

PORTNAME=	centerim
PORTVERSION=	4.22.7
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.centerim.org/download/releases/ \
		ftp://ftp.centerim.org/releases/

MAINTAINER=	frank@altpeter.de
COMMENT=	A text mode menu- and window-driven IM interface

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="-I${LOCALBASE}/include ${CXXFLAGS}"
CONFIGURE_ARGS=	--with-ssl --with-openssl --disable-konst
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFLICTS=	centericq-[0-9]* centerim-devel-[0-9]*

OPTIONS=	NLS             "Native Language Support" on \
		MULTIBYTE       "Multibyte Support" off \
		FRIBIDI         "Fribidi Support" off \
		MSN             "Support for MSN Protocol" off \
		YAHOO           "Support for Yahoo! Messenger Protocol" off \
		AIM             "Support for AOL's Instant Messenger Protocol" off \
		IRC             "Support for IRC Protocol" off \
		JABBER          "Support for Jabber Protocol" off \
		GPGME           "Support for PGP encrypted Jabber messages" off \
		RSS             "Support for RSS" off \
		LJ              "Support for LiveJournal" off \
		GG              "Support for Gadu-Gadu Protocol" off

MAN1=	cimconv.1 centerim.1

PORTDOCS=	FAQ README

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.if defined(WITH_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif

.if defined(WITH_FRIBIDI)
LIB_DEPENDS+=		fribidi.3:${PORTSDIR}/converters/fribidi
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
.else
.endif

.if !defined(WITH_GPGME)
CONFIGURE_ARGS+=	--without-gpgme
.else
LIB_DEPENDS+=		gpgme.18:${PORTSDIR}/security/gpgme
#CONFIGURE_ARGS+=	--with-gpgme=${LOCALBASE}
CONFIGURE_ARGS+=	--with-ssl
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
LIB_DEPENDS+=		gadu.3:${PORTSDIR}/polish/ekg
LIBGADU=		-lgadu
.endif

post-patch:
	@${REINPLACE_CMD} -e '1 s|/usr/bin/python|/usr/bin/env python|' \
		${WRKSRC}/misc/CenterIMLog2HTML.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
