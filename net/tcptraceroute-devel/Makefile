# New ports collection makefile for:   tcptraceroute-devel
# Date created:        12 December 2007
# Whom:                josh.carroll@gmail.com
#
# $FreeBSD$
#

PORTNAME=	tcptraceroute
DISTVERSION=	1.5beta7
CATEGORIES=	net
MASTER_SITES=	http://michael.toren.net/code/tcptraceroute/ \
		http://pflog.net/tcptraceroute/
PKGNAMESUFFIX=	-devel

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	A traceroute implementation using TCP packets

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

CONFLICTS=	tcptraceroute-1.4*

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	tcptraceroute.1

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

CONFIGURE_ARGS=		--with-libpcap=/usr --bindir=${PREFIX}/sbin

INSTALL_TARGET=	install-exec-am install-man

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
