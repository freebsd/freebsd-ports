# $FreeBSD$

PORTNAME=	Grutatxt
PORTVERSION=	2.20
CATEGORIES=	textproc perl5
MASTER_SITES=	https://triptico.com/download/ \
		LOCAL/jhale
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME:tl}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Plain text to HTML (and other formats) converter

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
