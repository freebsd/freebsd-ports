# $FreeBSD$

PORTNAME=	pktanon
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tm.uka.de/software/pktanon/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-dev

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Network trace anonymizer

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs \
		xerces-c:${PORTSDIR}/textproc/xerces-c2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

post-install:
	${MKDIR} ${DATADIR}/profiles
	(cd ${WRKSRC}/profiles/ && ${COPYTREE_SHARE} \* ${DATADIR}/profiles)

.include <bsd.port.mk>
