# Created by: matusita@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	jwhois
PORTVERSION=	4.0
#PORTREVISION=	0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	jwhois

MAINTAINER=	ports@FreeBSD.org
COMMENT=An improved WHOIS client capable of selecting server to query

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=		gettext gmake
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/var/jwhois

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

INSTALL_TARGET=	install-strip

INFO=	jwhois

.include <bsd.port.pre.mk>

.if exists(${FILESDIR}/jwhois.conf)
JWHOIS_CONF_SRC=${FILESDIR}/jwhois.conf
.else
JWHOIS_CONF_SRC=${WRKSRC}/example/jwhois.conf
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/var/jwhois
	${INSTALL_DATA} ${JWHOIS_CONF_SRC} ${STAGEDIR}${PREFIX}/etc/jwhois.conf.sample

.include <bsd.port.post.mk>
