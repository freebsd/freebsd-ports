# New ports collection makefile for:    ifmail
# Version required:     2.14
# Date created:         19 Feb 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.7 1998/04/19 15:43:29 steve Exp $
#

DISTNAME=       ifmail-2.14
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.average.org/ifmail/ \
		ftp://ftp.dinoex.sub.de/pub/approved/
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=     dirk.meyer@dinoex.sub.org

MAN3=		parsedate.3
MAN8=		ifmail.8 iftoss.8

pre-install:
	@PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL
	${MKDIR} ${PREFIX}/libexec/ifmail

post-install:
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/ifgate/${i} ${PREFIX}/man/man8
.endfor
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/iflib/${i} ${PREFIX}/man/man3
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ifmail
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ifmail
.for i in ifcico ifgate iflib
	${INSTALL_DATA} ${WRKSRC}/${i}/README ${PREFIX}/share/doc/ifmail/README.${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/ifmail
	@cd ${WRKSRC}/misc; tar cf - . | (cd ${PREFIX}/share/examples/ifmail; tar xf -)

.include <bsd.port.mk>
