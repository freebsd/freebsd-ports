# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	demoroniser
PORTVERSION=	1.0.20030916
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.fourmilab.ch/webtools/demoroniser/ \
		LOCAL/jedgar
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Correct moronic and gratuitously incompatible HTML from MS applications

USES=		perl5 shebangfix zip
USE_PERL5=	run
perl_OLD_CMD=	/bin/perl
SHEBANG_FILES=	demoroniser.pl
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/demoroniser man/man1/demoroniser.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/demoroniser.pl \
		${STAGEDIR}${PREFIX}/bin/demoroniser
	${INSTALL_MAN} ${WRKDIR}/demoroniser.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
