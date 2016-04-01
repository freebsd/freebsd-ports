# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=	gpgdir
PORTVERSION=	1.9.5
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	https://www.cipherdyne.org/~cipherdy/gpgdir/download/ \
		http://www.cipherdyne.org/gpgdir/download/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Recursive directory encryption with GnuPG

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Class-MethodMaker>=0:devel/p5-Class-MethodMaker \
		p5-GnuPG-Interface>=0:security/p5-GnuPG-Interface \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	gpgdir

PLIST_FILES=	bin/gpgdir man/man1/gpgdir.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gpgdir ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gpgdir.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
