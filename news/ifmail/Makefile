# New ports collection makefile for:    ifmail
# Version required:     2.10
# Date created:         19 Feb 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $Id$
#

DISTNAME=       ifmail-2.10
CATEGORIES=	news
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/ \
		${MASTER_SITE_SUNSITE} \
		ftp://ftp.demos.su/unix/linux/source/fido/ \
		ftp://net2.dinoex.sub.org/pub/approved/
MASTER_SITE_SUBDIR=	system/Mail/transport/

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
