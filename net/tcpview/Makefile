PORTNAME=	tcpview
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://ftp.vim.org/ibiblio/system/network/management/ \
		ftp://ftp.ottix.net/pub/mirrors/by-package/tcpview/ \
		ftp://ftp.ibiblio.org/pub/historic-linux/ftp-archives/sunsite.unc.edu/Sep-29-1996/system//Network/management/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif-based TCP/IP protocol analyzer

MAKE_JOBS_UNSAFE=	yes

USES=		bison motif tar:Z
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

post-patch:
.for f in nametoaddr.c addrtoname.c print-nfs.c detail-tcp.c tv_addrtoname.c
	@${REINPLACE_CMD} -e 's/NTOHL/ntohl/ ; s/NTOHS/ntohs/' ${WRKSRC}/${f}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/DOC/Tcpview ${STAGEDIR}${PREFIX}/lib/X11/app-defaults

.include <bsd.port.mk>
