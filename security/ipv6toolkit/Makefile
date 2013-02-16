# $FreeBSD$

PORTNAME=	ipv6toolkit
PORTVERSION=	1.3
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.si6networks.com/tools/ipv6toolkit/
DISTNAME=	ipv6-toolkit-v${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A set of IPv6 security assessment tools

LICENSE=	GPLv3

MAKE_ENV=	DATADIR=${DATADIR}
MAKE_JOBS_SAFE=	yes
PORTDOCS=	README.TXT
MAN1=		flow6.1 frag6.1 icmp6.1 jumbos6.1 na6.1 ni6.1 ns6.1 ra6.1 \
		rd6.1 rs6.1 scan6.1 tcp6.1
MAN5=		ipv6toolkit.conf.5

post-patch:
	${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
		${WRKSRC}/data/ipv6toolkit.conf

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
