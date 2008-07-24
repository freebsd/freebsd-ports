# New ports collection makefile for:   freenet6
# Date created:        11 Oct 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	freenet6
PORTVERSION=	5.1
PORTREVISION=	11
CATEGORIES=	net ipv6
MASTER_SITES=	http://go6.net/4105/file.asp?file_id=150&
DISTNAME=	tspc-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Hexago Freenet6 Tunnel Setup Protocol Client - Free IPv6 tunnel

USE_RC_SUBR=	yes
WRKSRC=		${WRKDIR}/tspc-advanced

MAN8=		gw6c.8
MAN5=		gw6c.conf.5

PKGMESSAGE=	${WRKDIR}/pkg-message
USE_RC_SUBR=	freenet6
SUB_FILES=	pkg-message
MAKE_ARGS=	target=freebsd installdir=${PREFIX}

PLIST_FILES=	bin/gw6c bin/gw6c-freebsd.sh share/examples/freenet6/gw6c.conf
PLIST_DIRS=	share/examples/freenet6

.include <bsd.port.pre.mk>

post-fetch:
	if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${MV} ${DISTDIR}/file.asp*file_id*150* \
		    ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gw6c ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/template/freebsd.sh ${PREFIX}/bin/gw6c-freebsd.sh
	${MKDIR} ${PREFIX}/share/examples/freenet6
	${INSTALL_DATA} ${WRKSRC}/bin/gw6c.conf.sample ${PREFIX}/share/examples/freenet6/gw6c.conf
	${INSTALL_MAN} ${WRKSRC}/man/man5/gw6c.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/man8/gw6c.8 ${PREFIX}/man/man8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
