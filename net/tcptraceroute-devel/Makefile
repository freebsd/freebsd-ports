# Created by: josh.carroll@gmail.com
# $FreeBSD$

PORTNAME=	tcptraceroute
DISTVERSION=	1.5beta7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://BSDforge.com/projects/source/net/tcptraceroute/ \
		http://pflog.net/tcptraceroute/
PKGNAMESUFFIX=	-devel

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Traceroute implementation using TCP packets

LICENSE=	GPLv2

LIB_DEPENDS=	libnet.so:net/libnet

CONFLICTS=	tcptraceroute-1.4*

PORTDOCS=	tcptraceroute.1.html tcptraceroute.lsm AUTHORS \
		COPYING ChangeLog NEWS README examples.txt

OPTIONS_DEFINE=	DOCS
USES=		gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-libnet=${LOCALBASE} --with-libpcap=/usr --bindir=${PREFIX}/sbin

post-install:
	@${CHMOD} u+s ${STAGEDIR}${PREFIX}/sbin/tcptraceroute
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
