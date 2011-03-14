# Ports collection makefile for:	jggtrans
# Date created:				13 September 2006
# Whom:					Bartek Rutkowski <r@robakdesign.com>
#
# $FreeBSD$

PORTNAME=		jggtrans
PORTVERSION=		2.2.4
PORTREVISION=		2
CATEGORIES=		net-im polish
MASTER_SITES=		http://jggtrans.jajcus.net/downloads/ \
			http://freebsd.e.pl/distfiles/

MAINTAINER=		mg@fork.pl
COMMENT=		Jabberd XMPP to GG instant messaging service gateway

LIB_DEPENDS=		idn.17:${PORTSDIR}/dns/libidn \
			expat.6:${PORTSDIR}/textproc/expat2 \
			gadu.3:${PORTSDIR}/polish/libgadu

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_GETTEXT=		yes
USE_GNOME=		glib20 pkgconfig
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=		-I${LOCALBASE}/include
MAKE_ENV=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

USE_RC_SUBR=		jggtrans.sh

OPTIONS=		NODEBUG "Turn off debugging code" off \
			EJABBERD "Use transport with ejabberd" off

.include <bsd.port.pre.mk>

.if defined(WITH_NODEBUG)
CONFIGURE_ARGS+=	--disable-debug
.endif

.if defined(WITH_EJABBERD)
JABBER_USER?=	ejabberd
SUB_LIST+=	JABBER_REQUIRE=ejabberd
.else
JABBER_USER?=	jabber
SUB_LIST+=	JABBER_REQUIRE=jabberd
.endif

SUB_LIST+=	JABBER_USER=${JABBER_USER}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/jggtrans.xml ${PREFIX}/etc/jggtrans.xml.sample
	@${CP} -n ${WRKSRC}/jggtrans.xml ${PREFIX}/etc/jggtrans.xml
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
