# Created by: Munechika SUMIKAWA <sumikawa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dhcp6
PORTVERSION=	20080615
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	SF/wide-dhcpv6/wide-dhcpv6/wide-dhcpv6-${PORTVERSION}
DISTNAME=	wide-dhcpv6-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	KAME DHCP6 client, server, and relay

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --with-localdbdir=/var/db
USE_RC_SUBR=	dhcp6c dhcp6relay dhcp6s
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

MAN5=		dhcp6c.conf.5 dhcp6s.conf.5
MAN8=		dhcp6c.8 dhcp6s.8 dhcp6relay.8 dhcp6ctl.8

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} \
		dhcp6c.conf.sample dhcp6s.conf.sample \
		${PREFIX}/etc
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
