# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	freenet6
DISTVERSION=	6_0_1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://go6.net/4105/file.asp?file_id=166&
DISTNAME=	tspc-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hexago Freenet6 Tunnel Setup Protocol Client - Free IPv6 tunnel

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../CLIENT-LICENSE.TXT

USES=		gmake ssl tar:tgz
MAKE_ARGS=	target=freebsd CC="${CC}" CXX="${CXX}" \
		installdir="${STAGEDIR}${PREFIX}" ETCDIR="${ETCDIR}"

WRKSRC=		${WRKDIR}/gw6c-${DISTVERSION}/tspc-advanced

USE_RC_SUBR=	freenet6
SUB_FILES=	pkg-message

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct dsa_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct dsa_st'
.endif

post-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${MV} ${DISTDIR}/file.asp*file_id*166* \
			${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

.include <bsd.port.post.mk>
