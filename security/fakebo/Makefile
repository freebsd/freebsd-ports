# New ports collection makefile for:   fakebo
# Version required:    0.4.1
# Date created:        16 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	fakebo-0.4.1
CATEGORIES=	security
MASTER_SITES=	http://yi.com/home/KosturjakVlatko/ \
		ftp://ftp.bitcon.no/.4/console/adm/ \
		ftp://ftp.iinet.net.au/mirrors1/berg/files/console/adm/ \
		ftp://ftp.linux.hr/pub/fakebo/

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=	yes

MAN1=		fakebo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fakebo ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/fakebo.conf.dist ${PREFIX}/etc/fakebo.conf.sample
	${INSTALL_MAN} ${WRKSRC}/fakebo.1 ${PREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fakebo/
	${INSTALL_MAN} ${WRKSRC}/custom.replies ${PREFIX}/share/doc/fakebo/
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/fakebo/
.endif

.include <bsd.port.mk>
