PORTNAME=	bsnmp-regex
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	LOCAL/olivier

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	bsnmpd module allowing creation of counters from log files
WWW=		http://thewalter.net/stef/software/bsnmp-regex/

LICENSE=	BSD3CLAUSE

USES=		libtool localbase

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/sockin lib/snmp_regex.so lib/snmp_regex.so.0 \
		lib/snmp_regex.so.0.0.0 lib/snmp_regex.a share/man/man1/sockin.1.gz \
		share/man/man5/bsnmp-regex.conf.5.gz \
		share/man/man8/bsnmp-regex.8.gz

# OPTION PCRE is safe to be removed when devel/pcre is removed
# CONFIGURE_ARGS+=	--disable-pcre
OPTIONS_DEFINE=	DEBUG PCRE

PCRE_DESC=	Use PCRE instead of the default regex library

DEBUG_CONFIGURE_ENABLE=debug
PCRE_LIB_DEPENDS=		libpcre.so:devel/pcre
PCRE_CONFIGURE_ENABLE=pcre

.include <bsd.port.mk>
