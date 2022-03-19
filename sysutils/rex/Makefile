# Created by: Zeus Panchenko <zeus@gnu.org.ua>

PORTNAME=	rex
PORTVERSION=	4.1
CATEGORIES=	sysutils tcl
MASTER_SITES=	http://download.gnu.org.ua/pub/release/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Remote EXecution utility

LICENSE=	GPLv3+

RUN_DEPENDS=	expect:lang/expect

NO_BUILD=	yes

PLIST_FILES=	bin/rex man/man8/rex.8.gz

do-install:
	cd ${WRKSRC} && ${WRKSRC}/install --prefix=${STAGEDIR}${PREFIX} \
		--sysconfdir=${PREFIX}/etc \
		--mandir=${STAGEDIR}${MANPREFIX}/man

.include <bsd.port.mk>
