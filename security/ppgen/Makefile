# Ports collection makefile for:  ppgen
# Date created:                   22 Aug 2001
# Whom:                           Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ppgen
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/ppgen/
DISTFILES=	${DISTNAME}.tar.gz en.gz
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure passphrase generator

GNU_CONFIGURE=	yes

MAN1=		ppgen.1

post-install:
	${MKDIR} ${PREFIX}/share/ppgen
	${GZIP_CMD} -dc ${DISTDIR}/en.gz > ${PREFIX}/share/ppgen/en

.include <bsd.port.mk>
