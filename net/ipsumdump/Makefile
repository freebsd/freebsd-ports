# Created by: krion@FreeBSD.org
# $FreeBSD$

PORTNAME=	ipsumdump
PORTVERSION=	1.82
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cs.ucla.edu/~kohler/ipsumdump/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Produce ASCII summary of network traffic or tcpdump(1) file

GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes

MAN1=		${PORTNAME}.1 ipaggcreate.1 ipaggmanip.1

PORTDOCS=	README
PLIST_FILES=	bin/ipaggcreate bin/ipsumdump bin/ipaggmanip

OPTIONS_DEFINE=	IPV6 DOCS

.include  <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
.if defined(WITH_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
PLIST_SUB+=	IPV6=""
.else
CONFIGURE_ARGS+=--disable-ipv6
PLIST_SUB+=	IPV6="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
