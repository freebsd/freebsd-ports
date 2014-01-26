# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	filepp
PORTVERSION=	1.8.0
CATEGORIES=	textproc
MASTER_SITES=	http://www-users.york.ac.uk/~dm26/filepp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A generic file preprocessor

USES=		perl5 shebangfix
GNU_CONFIGURE=	yes
NO_BUILD=	yes
CONFIGURE_ENV=	PERL=${PERL}

post-patch:
	@${REINPLACE_CMD} -e 's|$$(moduledir)|$$(DESTDIR)$$(moduledir)|' \
		${WRKSRC}/modules/*/Makefile.in

.include <bsd.port.mk>
