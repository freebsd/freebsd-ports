# New ports collection makefile for: achievo
# Date created:		19 Jan 2001
# Whom:			mkptools
#
# $FreeBSD$
#

PORTNAME=	achievo
PORTVERSION=	1.0.4
CATEGORIES=	misc www
MASTER_SITES=	http://www.achievo.org/files/ \
		http://www.caomhin.org/geek/ports/
DISTNAME=	${PORTNAME}-stable-${PORTVERSION}

MAINTAINER=	kevin@caomhin.demon.co.uk
COMMENT=	A flexible web-based resource management tool

USE_PHP=	yes
WANT_PHP_MOD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	YES

post-patch:
	@${MV} ${WRKSRC}/config.inc.php ${WRKSRC}/config.inc.php-default

do-install:
	@${MKDIR} ${PREFIX}/www/data.default/achievo
	@${CP} -R ${WRKSRC}/* ${PREFIX}/www/data.default/achievo/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
