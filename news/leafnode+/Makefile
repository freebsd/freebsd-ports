# New ports collection makefile for:	leafnode+
# Version required:	0.9.8a
# Date created:		19 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $Id$
#

DISTNAME=	leafnode+-1.2
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.big.or.jp/pub/usr2/jam/leafnode/

MAINTAINER=	tom@eborcom.com

MAN8=		checkgroups.8 fetch-news.8 leafnode.8 texpire.8

.if defined(NOPORTDOCS)
PLIST=	${PKGDIR}/PLIST.nodocs
.endif

post-patch:
.for file in FAQ INSTALL README leafnode.8
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.bak
	@${SED} < ${WRKSRC}/${file}.bak > ${WRKSRC}/${file} s+!!PREFIX!!+${PREFIX}+g
.endfor

do-install:
	@${CP} ${WRKSRC}/fetch.8 ${WRKSRC}/fetch-news.8
.for file in leafnode fetch-news texpire checkgroups leaftool
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/sbin
.endfor
.for file in checkgroups.8 fetch-news.8 leafnode.8 texpire.8
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man8
.endfor
.if !defined{NOPORTDOCS}
	@${ECHO} "===>  Copying documents to ${PREFIX}/share/doc/leafnode+"
	@${MKDIR} ${PREFIX}/share/doc/leafnode+
.for file in Changes FAQ INSTALL README config.example
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/leafnode+
.endfor
.endif

.include <bsd.port.mk>
