# New ports collection makefile for:	jailuser
# Date created:				10 Jun 2004
# Whom:					bugghy <bugghy@SAFe-mail.net>
#
# $FreeBSD$
#

PORTNAME=	jailuser
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jail
DISTNAME=	jail_${PORTVERSION}

MAINTAINER=	bugghy@SAFe-mail.net
COMMENT=	Builds a chrooted environment

WRKSRC=		${WRKDIR}/jail_1-9_stable/src
USE_PERL5=	yes

post-patch:
	@${SED} -e 's!/usr/bin/perl!${PERL}!g' ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/SECURITY ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/VERSION ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/download ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/features ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/intro ${DOCSDIR}
.endif

	@${SED} -e 's!PREFIX!${PREFIX}!g' ${.CURDIR}/pkg-message

.include <bsd.port.mk>
