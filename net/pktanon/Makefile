# $FreeBSD$

PORTNAME=	pktanon
PORTVERSION=	1.4.0
PORTREVISION=	16
CATEGORIES=	net
MASTER_SITES=	http://www.tm.uka.de/software/pktanon/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-dev

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network trace anonymizer

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libxerces-c.so.3:textproc/xerces-c3

USES=		compiler:c++0x dos2unix localbase

GNU_CONFIGURE=	yes
LDFLAGS+=	-lboost_system

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/profiles
	(cd ${WRKSRC}/profiles/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/profiles)

.include <bsd.port.mk>
