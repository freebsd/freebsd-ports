# Created by: Dan Moschuk <dan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sshbuddy
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://linuxmafia.com/pub/linux/security/sshbuddy/

MAINTAINER=	wrighrc@gmail.com
COMMENT=	Simple and small GUI utility to manage ssh sessions

RUN_DEPENDS=	expectk:${PORTSDIR}/lang/expect

USES=			shebangfix
USE_XORG=		x11
SHEBANG_FILES=		${WRKSRC}/sshbuddy.expk
SHEBANG_LANG=		expectk
expectk_OLD_CMD=	/usr/bin/expectk
expectk_CMD=		${LOCALBASE}/bin/expectk

NO_BUILD=	yes
PLIST_FILES=	bin/sshbuddy

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/sshbuddy.expk ${STAGEDIR}${PREFIX}/bin/sshbuddy

.include <bsd.port.mk>
