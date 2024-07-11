PORTNAME=	ipsumdump
DISTVERSION=	1.86
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://read.seas.harvard.edu/~kohler/ipsumdump/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Produce ASCII summary of network traffic or tcpdump(1) file
WWW=		https://read.seas.harvard.edu/~kohler/ipsumdump

LICENSE=	CLICK
LICENSE_NAME=	Click license
LICENSE_FILE=	${WRKSRC}/libclick-2.1/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake perl5
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_PERL5=	build

PORTDOCS=	README.md
PLIST_FILES=	bin/ipaggcreate bin/ipsumdump bin/ipaggmanip \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man1/ipaggmanip.1.gz \
		share/man/man1/ipaggcreate.1.gz

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
