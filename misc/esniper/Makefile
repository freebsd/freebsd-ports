# Created by: Lewis Thompson <lewiz@compsoc.man.ac.uk>
# $FreeBSD$

PORTNAME=	esniper
DISTVERSION=	2-35-0
PORTREVISION= 	2
CATEGORIES=	misc net
MASTER_SITES=	https://sourceforge.net/code-snapshots/git/e/es/esniper/git.git/
DISTNAME=	${PORTNAME}-git-91d2665539beaeac21fb4c0cc2fd39c44e771ed7

MAINTAINER=	ag-freebsd@muc.de
COMMENT=	Lightweight console application for sniping ebay auctions

LICENSE=	BSD2CLAUSE

BROKEN=		Incompatible with eBay website changes

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		zip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-curl-config=${LOCALBASE}/bin/curl-config

PLIST_FILES=	bin/esniper man/man1/esniper.1.gz

PORTEXAMPLES=	sample_auction.txt sample_config.txt

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
