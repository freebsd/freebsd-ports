# Created by: brock@cotcomsol.com
# $FreeBSD$

PORTNAME=	bsnmp-regex
PORTVERSION=	0.6
CATEGORIES=	net-mgmt
MASTER_SITES=	http://thewalter.net/stef/software/bsnmp-regex/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	bsnmpd module allowing creation of counters from log files

LICENSE=	BSD

GNU_CONFIGURE=	yes
CPPFLAGS+=	"-I${LOCALBASE}/include"

OPTIONS_DEFINE=	DEBUG PCRE
PCRE_DESC=	Use PCRE instead of the default regex library

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=		pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--enable-pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

MAN1=		sockin.1
MAN5=		bsnmp-regex.conf.5
MAN8=		bsnmp-regex.8

PLIST_FILES=	bin/sockin lib/snmp_regex.so lib/snmp_regex.so.0 \
		lib/snmp_regex.a lib/snmp_regex.la

.include <bsd.port.mk>
