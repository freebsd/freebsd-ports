# Created by: krion@FreeBSD.org
# $FreeBSD$

PORTNAME=	icpld
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.ibiblio.org/icpld/download/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Internet connection performance logging daemon

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1

PORTDOCS=	README
PLIST_FILES=	bin/icpld etc/icpld.conf.sample etc/rc.d/icpld.sh.sample

OPTIONS_DEFINE=	IPV6 DOCS

.include  <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${ECHO_MSG} '===> Installing ${PREFIX}/etc/icpld.conf.sample file.'
	${INSTALL_DATA} ${WRKSRC}/icpld.conf.sample ${PREFIX}/etc
	@${ECHO_MSG} '===> Installing ${PREFIX}/etc/rc.d/icpld.sh.sample'
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/icpld.sh.sample ${PREFIX}/etc/rc.d

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
