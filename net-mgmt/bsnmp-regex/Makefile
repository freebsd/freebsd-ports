# Created by: brock@cotcomsol.com
# $FreeBSD$

PORTNAME=	bsnmp-regex
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://thewalter.net/stef/software/bsnmp-regex/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	bsnmpd module allowing creation of counters from log files

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
CPPFLAGS+=	"-I${LOCALBASE}/include"
INSTALL_TARGET=	install-strip
USES=		libtool

OPTIONS_DEFINE=	DEBUG PCRE
PCRE_DESC=	Use PCRE instead of the default regex library

PLIST_FILES=	bin/sockin lib/snmp_regex.so lib/snmp_regex.so.0 \
		lib/snmp_regex.so.0.0.0 lib/snmp_regex.a man/man1/sockin.1.gz \
		man/man5/bsnmp-regex.conf.5.gz \
		man/man8/bsnmp-regex.8.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=		libpcre.so:devel/pcre
CONFIGURE_ARGS+=	--enable-pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.include <bsd.port.mk>
