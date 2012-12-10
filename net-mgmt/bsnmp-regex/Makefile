# Created by: brock@cotcomsol.com
# $FreeBSD$

PORTNAME=	bsnmp-regex
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://memberwebs.com/stef/software/bsnmp-regex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bsnmpd module allowing creation of counters from log files

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	PCRE
PCRE_DESC=	Use PCRE instead of the default regex library

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=		pcre.3:${PORTSDIR}/devel/pcre
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
