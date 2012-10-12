# $FreeBSD$

PORTNAME=	igor
PORTVERSION=	1.330
CATEGORIES=	textproc
MASTER_SITES=	http://www.glenbarber.us/ports/${CATEGORIES}/${PORTNAME}/

MAINTAINER=	wblock@FreeBSD.org
COMMENT=	FreeBSD Documentation Project sanity check script

LICENSE=	BSD

USE_PERL5_RUN=	yes

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
