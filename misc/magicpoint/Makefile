# New ports collection makefile for:	magicpoint
# Version required:	1.03a
# Date created:		24 December 1997
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.2 1998/02/17 12:58:54 itojun Exp $
#

DISTNAME=	mgp-1.03a
PKGNAME?=	magicpoint-1.03a
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=	itojun@itojun.org

USE_IMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-vflib

DOCS=	COPYRIGHT COPYRIGHT.jp README SYNTAX TODO.jp USAGE USAGE.jp
SAMPLES=	README README.jp ascii.mgp cloud.gif dad.eps dad.gif dns.mgp \
		default.mgp gradation.mgp mgp-old1.gif mgp-old2.gif \
		mgp-old3.gif mgp1.gif mgp2.gif mgp3.gif sample.mgp \
		tutorial.mgp v6.mgp v6header.eps v6header.gif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mgp
	for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/mgp; \
	done
	${MKDIR} ${PREFIX}/share/doc/mgp/sample
	for i in $(SAMPLES); do \
		${INSTALL_DATA} ${WRKSRC}/sample/$$i ${PREFIX}/share/doc/mgp/sample; \
	done
.endif

.include <bsd.port.mk>
