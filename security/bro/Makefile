# ex:ts=8
# Ports collection makefile for:  bro
# Version required:     	  0.3alpha
# Date created:			  Sat Feb 28, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.1.1.1 1998/03/02 10:35:04 obrien Exp $
#

DISTNAME=	vp-bro-0.3-alpha
PKGNAME=	bro-0.3a
CATEGORIES=	security net
MASTER_SITES=	ftp://ee.lbl.gov/  \
		ftp://ftp.nuxi.com/pub/misc/

MAINTAINER=     obrien@NUXI.com

WRKSRC=		${WRKDIR}/bro-0.3
CONFIGURE_ARGS= --libdir=${PREFIX}/share
GNU_CONFIGURE=	yes

post-patch:
	@${MV} ${WRKSRC}/util.cc ${WRKSRC}/util.cc.in
	@${SED} -e "s|/usr/src/rtsg/bro/policy:/usr/local/lib/bro|${PREFIX}/share/bro|" \
		${WRKSRC}/util.cc.in >${WRKSRC}/util.cc
pre-install:
	@${MKDIR} ${PREFIX}/share/bro

post-install:
	@strip ${PREFIX}/sbin/bro
	@${INSTALL_DATA} ${WRKSRC}/policy/* ${PREFIX}/share/bro
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/bro
	${INSTALL_MAN} ${WRKSRC}/doc/bro-usenix98-revised.ps \
		${PREFIX}/share/doc/bro
	@${GZIP_CMD} ${PREFIX}/share/doc/bro/bro-usenix98-revised.ps
.endif

.include <bsd.port.mk>
