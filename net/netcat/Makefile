# ex:ts=8
# Ports collection makefile for:  netcat
# Date created:			  Thur Nov 21, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	netcat
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://coast.cs.purdue.edu/pub/tools/unix/netutils/netcat/  \
		ftp://ftp.cuhk.edu.hk/pub/packages/security/purdue/netutils/netcat/  \
		http://www.planetmirror.com/pub/lprng/TOOLS/
DISTNAME=	nc110
EXTRACT_SUFX=	.tgz

PATCH_SITES=	ftp://sith.mimuw.edu.pl/pub/users/baggins/IPv6/
PATCHFILES=	nc-v6-20000918.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sumikawa@FreeBSD.org

NO_WRKSUBDIR=	yes
ALL_TARGET=	freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/netcat \
		&& ${CHMOD} a+rx ${PREFIX}/share/doc/netcat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/netcat
.endif

.include <bsd.port.mk>
