# New ports collection makefile for:	icpld
# Date created:				04.01.2004
# Whom:					krion@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icpld
PORTVERSION=	1.1.4
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.ibiblio.org/icpld/download/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	Internet connection performance logging daemon

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		${PORTNAME}.1

PORTDOCS=	README
PLIST_FILES=	bin/icpld etc/icpld.conf.sample etc/rc.d/icpld.sh.sample

OPTIONS=	IPV6	"IPv6 internet support" off \

.include  <bsd.port.pre.mk>

.if defined(WITH_IPV6)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
