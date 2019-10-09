# Created by: krion@FreeBSD.org
# $FreeBSD$

PORTNAME=	icpld
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.ibiblio.org/icpld/download/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet connection performance logging daemon

USES=		tar:bzip2
GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/icpld etc/icpld.conf.sample etc/rc.d/icpld.sh.sample \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	IPV6 DOCS

IPV6_CONFIGURE_ENABLE=	ipv6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${ECHO_MSG} '===> Installing ${STAGEDIR}${PREFIX}/etc/icpld.conf.sample file.'
	${INSTALL_DATA} ${WRKSRC}/icpld.conf.sample ${STAGEDIR}${PREFIX}/etc
	@${ECHO_MSG} '===> Installing ${STAGEDIR}${PREFIX}/etc/rc.d/icpld.sh.sample'
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/icpld.sh.sample ${STAGEDIR}${PREFIX}/etc/rc.d

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
