# ex:ts=8
# Ports collection makefile for:  netcat
# Date created:			  Thur Nov 21, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	nc110
PKGNAME=	netcat-1.10
CATEGORIES=	net
MASTER_SITES=	ftp://avian.org/src/hacks/  \
		ftp://coast.cs.purdue.edu/pub/mirrors/avian.org/netcat/  \
		ftp://zippy.telcom.arizona.edu/pub/mirrors/avian.org/hacks/  \
		ftp://ftp.sterling.com/mirrors/avian.org/src/hacks/  \
		ftp://ftp.rge.com/pub/security/coast/mirrors/avian.org/netcat/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org

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
