# New ports collection makefile for:    pam-pgsql
# Date created:				Nov 16, 2000
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	pam-pgsql
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	security databases
MASTER_SITES=	SF
DISTNAME=	libpam-pgsql-${PORTVERSION}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A pam module for authenticating with PostgreSQL

LIB_DEPENDS=	mhash.2:${PORTSDIR}/security/mhash

USE_BZIP2=	yes
USE_PGSQL=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/lib//}

post-install:
post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/debian/changelog \
		${WRKSRC}/debian/copyright ${DOCSDIR}
.endif

.include <bsd.port.mk>
