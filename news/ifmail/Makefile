# New ports collection makefile for:    ifmail
# Date created:         19 Feb 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ifmail
PORTVERSION=	2.15
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.average.org/ifmail/
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dirk.meyer@dinoex.sub.org

MAN3=		parsedate.3
MAN8=		ifmail.8 iftoss.8

pre-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
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
