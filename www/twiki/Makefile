# Ports collection makefile for:  TWiki
# Date created:			  Fri Mar  7 14:36:05 CST 2003
# Whom:				  Justin Hawkins <justin@hawkins.id.au>
#
# $FreeBSD$
#

PORTNAME=	twiki
PORTVERSION=	20030201
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://twiki.org/swd/ http://www.thoeny.com/peter/twiki/
DISTNAME=      	TWiki${PORTVERSION}

MAINTAINER=	justin@hawkins.id.au
COMMENT=        A flexible, powerful, and easy to use Web-based collaboration platform

NO_WRKSUBDIR=   yes
NO_BUILD=	yes

USE_ZIP=	yes

LTWIKIDIR=	www/twiki

TWIKIDIR=	${PREFIX}/${LTWIKIDIR}

pre-configure:
# move config file to sample
	@${MV} ${WRKSRC}/lib/TWiki.cfg ${WRKSRC}/lib/TWiki.cfg.sample

do-install:
	${MKDIR} ${TWIKIDIR}
	${CP} -R ${WRKSRC}/* ${TWIKIDIR}/

post-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
