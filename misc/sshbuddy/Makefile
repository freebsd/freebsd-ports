# Created by: Dan Moschuk <dan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sshbuddy
PORTVERSION=	1.05
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://linuxmafia.com/pub/linux/security/sshbuddy/

MAINTAINER=	wrighrc@gmail.com
COMMENT=	Simple and small GUI utility to manage ssh sessions

RUN_DEPENDS=	expect:lang/expect

USES=		tk

NO_BUILD=	yes
PLIST_FILES=	bin/sshbuddy

post-patch:
	${REINPLACE_CMD} -e 's|%%WISH%%|${WISH}|' ${WRKSRC}/sshbuddy.expk

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sshbuddy.expk ${STAGEDIR}${PREFIX}/bin/sshbuddy

.include <bsd.port.mk>
