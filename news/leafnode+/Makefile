# New ports collection makefile for:	leafnode+
# Version required:	2.6
# Date created:		19 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $Id: Makefile,v 1.3 1999/01/10 18:10:09 steve Exp $
#

DISTNAME=	leafnode+-2.6
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.big.or.jp/pub/usr2/jam/leafnode/

MAINTAINER=	tom@eborcom.com

MAN8=		checkgroups.8 fetchnews.8 leafnode.8 texpire.8

.if defined(NOPORTDOCS)
PLIST=	${PKGDIR}/PLIST.nodocs
.endif

post-patch:
.for file in FAQ INSTALL README leafnode.8
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.bak
	@${SED} < ${WRKSRC}/${file}.bak > ${WRKSRC}/${file} s+!!PREFIX!!+${PREFIX}+g
.endfor

do-install:
.for file in leafnode fetchnews texpire checkgroups leaftool
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/sbin
.endfor
.for file in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man8
.endfor
.if !defined{NOPORTDOCS}
	@${ECHO} "===>  Copying documents to ${PREFIX}/share/doc/leafnode+"
	@${MKDIR} ${PREFIX}/share/doc/leafnode+
.for file in Changes FAQ INSTALL README config.example
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/leafnode+
.endfor
.endif

post-install:
	@test -d /var/spool/news -a -d ${PREFIX}/lib/leafnode || \
		${CAT} ${FILESDIR}/INSTALL.mesg

.include <bsd.port.mk>
