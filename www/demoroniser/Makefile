# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	demoroniser
PORTVERSION=	1.0.20030916
CATEGORIES=	www
MASTER_SITES=	http://www.fourmilab.ch/webtools/demoroniser/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jedgar
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Correct moronic and gratuitously incompatible HTML from MS applications

USES=		zip shebangfix
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/demoroniser man/man1/demoroniser.1.gz
SHEBANG_FILES=	demoroniser.pl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/demoroniser.pl \
		${STAGEDIR}${PREFIX}/bin/demoroniser
	${INSTALL_MAN} ${WRKDIR}/demoroniser.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
