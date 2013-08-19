# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ipsumdump
PORTVERSION=	1.82
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cs.ucla.edu/~kohler/ipsumdump/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Produce ASCII summary of network traffic or tcpdump(1) file

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build

MAN1=		${PORTNAME}.1 ipaggcreate.1 ipaggmanip.1

PORTDOCS=	README
PLIST_FILES=	bin/ipaggcreate bin/ipsumdump bin/ipaggmanip

OPTIONS_DEFINE=	IPV6 DOCS
OPTIONS_SUB=	yes

IPV6_CONFIGURE_ENABLE=	ipv6

.include <bsd.port.options.mk>

# Try to unbreak parallel (-jX) builds
post-patch:
	@${ECHO_CMD} 'src: @LIBCLICK_TARGET@' >> ${WRKSRC}/Makefile.in

.if ${PORT_OPTIONS:MIPV6}
CATEGORIES+=	ipv6
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
