PORTNAME=	listadmin
DISTVERSION=	2.40
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://heim.ifi.uio.no/kjetilho/hacks/

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Command-line alternative to Mailman Web interface
WWW=		http://heim.ifi.uio.no/kjetilho/hacks/ #listadmin

RUN_DEPENDS=	p5-Text-Reform>=0:textproc/p5-Text-Reform \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-libwww>=0:www/p5-libwww

USES=		perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	listadmin.pl

NO_ARCH=	yes

PLIST_FILES=	bin/listadmin share/man/man1/listadmin.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/listadmin.pl \
		${STAGEDIR}${PREFIX}/bin/listadmin
	${INSTALL_MAN} ${WRKSRC}/listadmin.man \
		${STAGEDIR}${PREFIX}/share/man/man1/listadmin.1

.include <bsd.port.mk>
