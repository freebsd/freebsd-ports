PORTNAME=	mail-expire
PORTVERSION=	0.9.2
CATEGORIES=	mail
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Expire old mails from mailboxes
WWW=		https://salsa.debian.org/blade/mail-expire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	p5-Mail-Mbox-MessageParser>=0:mail/p5-Mail-Mbox-MessageParser

USES=		gmake perl5 shebangfix tar:xz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes
SHEBANG_FILES=	mail-expire
PLIST_FILES=	bin/mail-expire ${MANPREFIX}/man/man1/mail-expire.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mail-expire ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/mail-expire.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
