# Created by: Bartek Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	jggtrans
PORTVERSION=	2.2.6
PORTREVISION=	3
CATEGORIES=	net-im polish
MASTER_SITES=	https://github.com/Jajcus/jggtrans/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabberd XMPP to GG instant messaging service gateway

LICENSE=	GPLv2

LIB_DEPENDS=	libidn.so:dns/libidn \
		libexpat.so:textproc/expat2 \
		libgadu.so:polish/libgadu

GNU_CONFIGURE=	yes
USES=		gettext gmake gnome pkgconfig
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

USE_RC_SUBR=	jggtrans

OPTIONS_DEFINE=	DEBUG EJABBERD
EJABBERD_DESC=	transport with ejabberd
DEBUG_CONFIGURE_ENABLE=debug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEJABBERD}
JABBER_USER?=	ejabberd
SUB_LIST+=	JABBER_REQUIRE=ejabberd
.else
JABBER_USER?=	jabber
SUB_LIST+=	JABBER_REQUIRE=jabberd
.endif

SUB_LIST+=	JABBER_USER=${JABBER_USER}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/jggtrans.xml ${STAGEDIR}${PREFIX}/etc/jggtrans.xml.sample

.include <bsd.port.mk>
