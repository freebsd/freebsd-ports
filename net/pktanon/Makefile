# New ports collection makefile for:   pktanon
# Date created:        9 March 2009
# Whom:                Wesley Shields <wxs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pktanon
PORTVERSION=	1.2.2
CATEGORIES=	net
MASTER_SITES=	http://www.tm.uka.de/software/pktanon/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-dev

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Network trace anonymizer

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost \
		xerces-c:${PORTSDIR}/textproc/xerces-c2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
MAKE_JOBS_SAFE=	yes

post-install:
	${MKDIR} ${DATADIR}/profiles
	(cd ${WRKSRC}/profiles/ && ${COPYTREE_SHARE} \* ${DATADIR}/profiles)

.include <bsd.port.mk>
