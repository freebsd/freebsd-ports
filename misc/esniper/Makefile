# Created by: Lewis Thompson <lewiz@compsoc.man.ac.uk>
# $FreeBSD$

PORTNAME=	esniper
DISTVERSION=	2-29-0
CATEGORIES=	misc net
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ag-freebsd@muc.de
COMMENT=	Lightweight console application for sniping ebay auctions

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-curl-config=${LOCALBASE}/bin/curl-config
USE_OPENSSL=	yes

PLIST_FILES=	bin/esniper man/man1/esniper.1.gz

PORTEXAMPLES=	sample_auction.txt sample_config.txt

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
