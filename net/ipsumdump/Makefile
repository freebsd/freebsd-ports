# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ipsumdump
PORTVERSION=	1.82
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.cs.ucla.edu/~kohler/ipsumdump/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Produce ASCII summary of network traffic or tcpdump(1) file

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build

PORTDOCS=	README
PLIST_FILES=	bin/ipaggcreate bin/ipsumdump bin/ipaggmanip \
		man/man1/${PORTNAME}.1.gz man/man1/ipaggmanip.1.gz \
		man/man1/ipaggcreate.1.gz

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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
