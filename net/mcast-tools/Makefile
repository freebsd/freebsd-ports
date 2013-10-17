# Created by: suz
# $FreeBSD$

PORTNAME=	mcast-tools
PORTVERSION=	20061214
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPv6 multicast routing daemons and tools

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake aclocal autoconf
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	YACC=${YACC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/pim6sd/pim6sd.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/pim6dd.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/mfc/mfc.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
