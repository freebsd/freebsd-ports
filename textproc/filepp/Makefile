# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	filepp
PORTVERSION=	1.8.0
CATEGORIES=	textproc
MASTER_SITES=	http://www-users.york.ac.uk/~dm26/filepp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic file preprocessor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL}
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(moduledir)|$$(DESTDIR)$$(moduledir)|' \
		${WRKSRC}/modules/*/Makefile.in

.include <bsd.port.mk>
