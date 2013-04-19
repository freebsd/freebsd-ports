# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	1.9
CATEGORIES=	devel
MASTER_SITES=	http://entrproject.org/code/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Runs arbitrary commands when files change

WRKSRC=	${WRKDIR}/eradman-entr-587c18272485/

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/entr

do-build:
	(cd ${WRKSRC} && ${MAKE} -f Makefile.bsd)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} entr ${PREFIX}/bin/)

.include <bsd.port.mk>
