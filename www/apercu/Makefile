# Created by: mich
# $FreeBSD$

PORTNAME=	apercu
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.incava.org/pub/apercu/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Summarize information from Apache logs

USE_RUBY=	yes
NO_BUILD=	yes

MAN1=		apercu.1
PLIST_FILES=	bin/apercu

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/ruby|${RUBY}|' ${WRKSRC}/apercu

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/apercu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/apercu.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
