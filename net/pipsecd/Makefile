# New ports collection makefile for:	pipsecd
# Version required:		19991014
# Date created:			16 Aug 1999
# Whom:				Patrick Bihan-Faou <patrick@mindstep.com>
#
# $FreeBSD$
#

DISTNAME=	pipsec-19991014
PKGNAME=	pipsecd-19991014
CATEGORIES=	net security
MASTER_SITES=	http://www.enst.fr/~beyssac/pipsec/ \
		http://www.mindstep.com/pipsec/

MAINTAINER=	patrick@mindstep.com

LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl

ALL_TARGET=	pipsecd

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipsecd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/pipsecd.sh ${PREFIX}/etc/rc.d
	${CHMOD} 755 ${PREFIX}/etc/rc.d/pipsecd.sh;
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
