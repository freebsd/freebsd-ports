# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ipsumdump
PORTVERSION=	1.86
CATEGORIES=	net
MASTER_SITES=	http://www.cs.ucla.edu/~kohler/ipsumdump/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Produce ASCII summary of network traffic or tcpdump(1) file

LICENSE=	CLICK
LICENSE_NAME=	Click license
LICENSE_FILE=	${WRKSRC}/libclick-2.1/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build

PORTDOCS=	README.md
PLIST_FILES=	bin/ipaggcreate bin/ipsumdump bin/ipaggmanip \
		man/man1/${PORTNAME}.1.gz man/man1/ipaggmanip.1.gz \
		man/man1/ipaggcreate.1.gz

OPTIONS_DEFINE=	IPV6 DOCS
OPTIONS_SUB=	yes

IPV6_CONFIGURE_ENABLE=	ipv6

# Try to unbreak parallel (-jX) builds
post-patch:
	@${ECHO_CMD} 'src: @LIBCLICK_TARGET@' >> ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ipsumdump
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ipaggcreate
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ipaggmanip

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
