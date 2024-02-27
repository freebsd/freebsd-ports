PORTNAME=	tcptrack
PORTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	https://BSDforge.com/projects/source/net-mgmt/tcptrack/ \
		http://pkgs.fedoraproject.org/repo/pkgs/tcptrack/tcptrack-1.4.2.tar.gz/dacf71a6b5310caf1203a2171b598610/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Packet sniffer that displays TCP information like top(1)
WWW=		https://BSDforge.com/projects/net-mgmt/tcptrack/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/tcptrack share/man/man1/tcptrack.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

.include <bsd.port.post.mk>
