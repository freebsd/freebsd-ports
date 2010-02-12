# New ports collection makefile for:   freenet6
# Date created:        11 Oct 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	freenet6
PORTVERSION=	6.0.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://go6.net/4105/file.asp?file_id=166&
DISTNAME=	tspc-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Hexago Freenet6 Tunnel Setup Protocol Client - Free IPv6 tunnel

USE_RC_SUBR=	yes
WRKSRC=		${WRKDIR}/gw6c-6_0_1/tspc-advanced

MAN8=		gw6c.8
MAN5=		gw6c.conf.5

USE_RC_SUBR=	freenet6
SUB_FILES=	pkg-message

USE_GMAKE=	yes
MAKE_ARGS=	target=freebsd installdir=${PREFIX} ETCDIR=${ETCDIR}

.include <bsd.port.pre.mk>

post-fetch:
	if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${MV} ${DISTDIR}/file.asp*file_id*166* \
		    ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
