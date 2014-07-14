# Created by: josh.carroll@gmail.com
# $FreeBSD$

PORTNAME=	tcptraceroute
DISTVERSION=	1.5beta7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://michael.toren.net/code/tcptraceroute/ \
		http://pflog.net/tcptraceroute/
PKGNAMESUFFIX=	-devel

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Traceroute implementation using TCP packets

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

CONFLICTS=	tcptraceroute-1.4*

USES=		gmake
GNU_CONFIGURE=	yes

MAN1=	tcptraceroute.1

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

CONFIGURE_ARGS=		--with-libpcap=/usr --bindir=${PREFIX}/sbin

INSTALL_TARGET=	install-exec-am install-man

NO_STAGE=	yes
post-install:
	@${CHMOD} u+s ${PREFIX}/sbin/tcptraceroute
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/tcptraceroute.1.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/tcptraceroute.lsm ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/examples.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
