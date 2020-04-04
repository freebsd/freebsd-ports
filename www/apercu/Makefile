# Created by: mich
# $FreeBSD$

PORTNAME=	apercu
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.incava.org/pub/apercu/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Summarize information from Apache logs

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

USE_RUBY=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/apercu man/man1/apercu.1.gz

pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/ruby|${RUBY}|' ${WRKSRC}/apercu

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/apercu ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/apercu.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
