# New ports collection makefile for:	ipsumdump
# Date created:				12.01.2004
# Whom:					krion@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ipsumdump
PORTVERSION=	1.61
CATEGORIES=	net
MASTER_SITES=	http://www.cs.ucla.edu/~kohler/ipsumdump/ \
		http://core.inec.ru/~az/

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	Produce ASCII summary of network traffic or tcpdump(1) file

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_PERL5_BUILD=yes
USE_GMAKE=	yes

MAN1=		${PORTNAME}.1 ipaggcreate.1

PORTDOCS=	README
PLIST_FILES=	bin/ipaggcreate bin/ipsumdump

OPTIONS=	 IPV6	"IPv6 internet support" off \

.include  <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
PLIST_SUB+=	IPV6=""
.else
CONFIGURE_ARGS+=--disable-ipv6
PLIST_SUB+=	IPV6="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
