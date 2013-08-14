# $FreeBSD$

PORTNAME=	pktanon
PORTVERSION=	1.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.tm.uka.de/software/pktanon/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-dev

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Network trace anonymizer

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs \
		xerces-c.3:${PORTSDIR}/textproc/xerces-c3

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lboost_system

post-install:
	${MKDIR} ${DATADIR}/profiles
	(cd ${WRKSRC}/profiles/ && ${COPYTREE_SHARE} \* ${DATADIR}/profiles)

.include <bsd.port.mk>
