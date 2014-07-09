# $FreeBSD$

PORTNAME=	bsnmp-jails
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://thewalter.net/stef/software/bsnmp-jails/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	bsnmpd module to measure statistics about jails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool

PLIST_FILES=	lib/snmp_jails.so lib/snmp_jails.so.0 \
		lib/snmp_jails.so.0.0.0 lib/snmp_jails.a \
		libexec/jail-measure \
		man/man8/bsnmp-jails.8.gz

.include <bsd.port.mk>
