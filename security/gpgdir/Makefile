# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=	gpgdir
PORTVERSION=	1.9.5
CATEGORIES=	security perl5
MASTER_SITES=	https://www.cipherdyne.org/~cipherdy/gpgdir/download/ \
		http://www.cipherdyne.org/gpgdir/download/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Recursive directory encryption with GnuPG

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Class-MethodMaker>=0:${PORTSDIR}/devel/p5-Class-MethodMaker \
		p5-GnuPG-Interface>=0:${PORTSDIR}/security/p5-GnuPG-Interface \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

NO_BUILD=	yes
USE_PERL5=	run
USES=		perl5

MAN1=		gpgdir.1
PLIST_FILES=	bin/gpgdir

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gpgdir ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/gpgdir.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
