# $FreeBSD$

PORTNAME=	bsnmp-jails
PORTVERSION=	0.10
CATEGORIES=	net-mgmt
MASTER_SITES=	http://thewalter.net/stef/software/bsnmp-jails/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A bsnmpd module to measure statistics about jails

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/snmp_jails.so lib/snmp_jails.so.0 \
		lib/snmp_jails.a lib/snmp_jails.la \
		libexec/jail-measure \
		man/man8/bsnmp-jails.8.gz

post-patch:
	${REINPLACE_CMD} -e 's|freebsd1|freebsd1.|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
