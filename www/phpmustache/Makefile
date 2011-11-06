# New ports collection makefile for:   phpmustache
# Date created:        25 October 2011
# Whom:                Steve Polyack <spolyack@collaborativefusion.com>
#
# $FreeBSD$
#

PORTNAME=	phpmustache
PORTVERSION=	0.8.1
CATEGORIES=	www
MASTER_SITES=	https://github.com/bobthecow/mustache.php/tarball/master/
DISTNAME=	bobthecow-mustache.php-v${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	spolyack@collaborativefusion.com
COMMENT=	PHP5 code for Mustache

GITVERSION=	1e23df0
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/bobthecow-mustache.php-${GITVERSION}

NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/Mustache.php ${DATADIR}
	@${MKDIR} ${DATADIR}/test
	@${INSTALL_DATA} ${WRKSRC}/test/*.php ${WRKSRC}/test/phpunit.xml ${DATADIR}/test
	@${MKDIR} ${DATADIR}/test/lib/yaml/doc ${DATADIR}/test/lib/yaml/lib
.for f in README.markdown LICENSE package.xml
	@${INSTALL_DATA} ${WRKSRC}/test/lib/yaml/$f ${DATADIR}/test/lib/yaml
.endfor
	@${INSTALL_DATA} ${WRKSRC}/test/lib/yaml/lib/* ${DATADIR}/test/lib/yaml/lib
	@${INSTALL_DATA} ${WRKSRC}/test/lib/yaml/doc/* ${DATADIR}/test/lib/yaml/doc
	@${MKDIR} ${DATADIR}/test/spec
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README.markdown LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
