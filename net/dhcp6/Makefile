# Created by: Munechika SUMIKAWA <sumikawa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dhcp6
PORTVERSION=	20080615.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2	
CATEGORIES=	net

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	KAME DHCP6 client, server, and relay

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd
GH_PROJECT=	wide-dhcpv6
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-localdbdir=/var/db
USE_RC_SUBR=	dhcp6c dhcp6relay dhcp6s
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} \
	    dhcp6c.conf.sample dhcp6s.conf.sample \
	    ${STAGEDIR}${PREFIX}/etc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
