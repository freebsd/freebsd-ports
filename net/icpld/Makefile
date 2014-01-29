# Created by: krion@FreeBSD.org
# $FreeBSD$

PORTNAME=	icpld
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.ibiblio.org/icpld/download/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Internet connection performance logging daemon

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/icpld etc/icpld.conf.sample etc/rc.d/icpld.sh.sample \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	IPV6 DOCS

.include  <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${ECHO_MSG} '===> Installing ${STAGEDIR}${PREFIX}/etc/icpld.conf.sample file.'
	${INSTALL_DATA} ${WRKSRC}/icpld.conf.sample ${STAGEDIR}${PREFIX}/etc
	@${ECHO_MSG} '===> Installing ${STAGEDIR}${PREFIX}/etc/rc.d/icpld.sh.sample'
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/icpld.sh.sample ${STAGEDIR}${PREFIX}/etc/rc.d

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
