# New ports collection makefile for:	pipsecd
# Version required:		19990519
# Date created:			16 Aug 1999
# Whom:				Patrick Bihan-Faou <patrick@mindstep.com>
#
# $FreeBSD$
#

DISTNAME=	tunip
PKGNAME=	pipsecd-19990519
CATEGORIES=	net security
MASTER_SITES=	http://www.enst.fr/~beyssac/

MAINTAINER=	patrick@mindstep.com

BUILD_DEPENDS=	${PREFIX}/lib/libcrypto.a:${PORTSDIR}/security/openssl:install

ALL_TARGET=		pipsecd

WRKSRC=		${WRKDIR}/pipsec-19990519

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipsecd ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/etc/ipsec
	${INSTALL_DATA} ${WRKSRC}/pipsecd.conf.sample ${PREFIX}/etc/ipsec
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pipsecd
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/pipsecd
	${INSTALL_MAN} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/pipsecd
	${INSTALL_MAN} ${WRKSRC}/README.port ${PREFIX}/share/doc/pipsecd
.endif

post-install:
	strip ${PREFIX}/sbin/pipsecd

.include <bsd.port.post.mk>
