PORTNAME=	tcpslice
DISTVERSION=	1.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://www.tcpdump.org/release/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Tool for extracting portions of pcap files
WWW=		https://www.tcpdump.org/related.html

LICENSE=	BSD3CLAUSE

USES=		cpe

CPE_VENDOR=	tcpdump

PLIST_FILES=	bin/tcpslice \
		share/man/man1/tcpslice.1.gz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
