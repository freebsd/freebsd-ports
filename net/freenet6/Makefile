# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	freenet6
DISTVERSION=	6_0_1
CATEGORIES=	net ipv6
MASTER_SITES=	http://go6.net/4105/file.asp?file_id=166&
DISTNAME=	tspc-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Hexago Freenet6 Tunnel Setup Protocol Client - Free IPv6 tunnel

USES=		gmake
MAKE_ARGS=	target=freebsd CC="${CC}" CXX="${CXX}" \
		installdir="${PREFIX}" ETCDIR="${ETCDIR}"

WRKSRC=		${WRKDIR}/gw6c-${DISTVERSION}/tspc-advanced

USE_RC_SUBR=	freenet6
SUB_FILES=	pkg-message

MAN5=		gw6c.conf.5
MAN8=		gw6c.8

post-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${MV} ${DISTDIR}/file.asp*file_id*166* \
			${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
