# Ports collection makefile for:  TWiki
# Date created:			  Fri Mar  7 14:36:05 CST 2003
# Whom:				  Justin Hawkins <justin@hawkins.id.au>
#
# $FreeBSD$
#

PORTNAME=	twiki
PORTVERSION=	20040902
CATEGORIES=	www
MASTER_SITES=	http://twiki.org/swd/ http://www.thoeny.com/peter/twiki/
DISTNAME=	TWiki${PORTVERSION}

MAINTAINER=	justin@hawkins.id.au
COMMENT=	A flexible, powerful, and easy to use Web-based collaboration platform

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_ZIP=	yes

LTWIKIDIR=	www/twiki

TWIKIDIR=	${PREFIX}/${LTWIKIDIR}

WWW_ROOT?=	www
PLIST_SUB+=	WWW_ROOT=${WWW_ROOT}

pre-everything::
	@${ECHO} "****************************************************************"
	@${ECHO} "*  If you're upgrading, Ctrl-C now and do the upgrade by hand. *"
	@${ECHO} "*  This software can't be upgraded automatically without       *"
	@${ECHO} "*  damaging data in your wiki!                                 *"
	@${ECHO} "****************************************************************"

pre-configure:
# move config file to sample
	@${MV} ${WRKSRC}/lib/TWiki.cfg ${WRKSRC}/lib/TWiki.cfg.sample

do-install:
	${MKDIR} ${TWIKIDIR}
	${CP} -R ${WRKSRC}/* ${TWIKIDIR}/

post-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
