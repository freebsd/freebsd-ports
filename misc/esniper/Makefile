# Created by: Lewis Thompson <lewiz@compsoc.man.ac.uk>
# $FreeBSD$

PORTNAME=	esniper
DISTVERSION=	2-31-0
CATEGORIES=	misc net
MASTER_SITES=	SF

MAINTAINER=	ag-freebsd@muc.de
COMMENT=	Lightweight console application for sniping ebay auctions

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-curl-config=${LOCALBASE}/bin/curl-config
USE_OPENSSL=	yes

PLIST_FILES=	bin/esniper man/man1/esniper.1.gz

PORTEXAMPLES=	sample_auction.txt sample_config.txt

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
