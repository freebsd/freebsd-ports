# ex:ts=8
# Ports collection makefile for:  ddos_scan
# Version required: 0.0
# Date created:			  Sun Feb 12, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	rid-1_0
PKGNAME=	rid-1.0
CATEGORIES=	security
MASTER_SITES=	http://packetstorm.securify.com/distributed/  \
		ftp://ftp.ntua.gr/pub/security/technotronic/denial/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/${PKGNAME}
ALL_TARGET=	rid

pre-configure:
	@${PERL} -pi -e 's:config.txt:${PREFIX}/etc/rid.conf:g'  \
		${WRKSRC}/config.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rid ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/config.txt ${PREFIX}/etc/rid.conf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rid
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/rid
.endif

.include <bsd.port.mk>
