PORTNAME=	filepp
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www-users.york.ac.uk/~dm26/filepp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic file preprocessor
WWW=		https://www-users.york.ac.uk/~dm26/filepp/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	PERL=${PERL}
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(moduledir)|$$(DESTDIR)$$(moduledir)|' \
		${WRKSRC}/modules/*/Makefile.in

.include <bsd.port.mk>
