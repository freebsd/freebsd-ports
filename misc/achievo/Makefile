# New ports collection makefile for: achievo
# Date created:		19 Jan 2001
# Whom:			mkptools
#
# $FreeBSD$
#

PORTNAME=	achievo
PORTVERSION=	1.0.2
CATEGORIES=	misc www
MASTER_SITES=	http://ftp.achievo.org/pub/achievo/
DISTNAME=	${PORTNAME}-stable-${PORTVERSION}

MAINTAINER=	kevin@caomhin.demon.co.uk
COMMENT=	A flexible web-based resource management tool

WANT_PHP_MOD=	yes
PHP_VER=	4
.include <../../lang/php4/bsd.php.mk>

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	YES

do-install:
	@${MKDIR} ${PREFIX}/www/data.default/achievo
	@${CP} -R ${WRKSRC}/* ${PREFIX}/www/data.default/achievo/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
