PORTNAME=	Grutatxt
PORTVERSION=	2.20
CATEGORIES=	textproc perl5
MASTER_SITES=	https://triptico.com/download/ \
		LOCAL/jhale/${PORTNAME:tl}/${PORTVERSION}
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME:tl}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME:tl}/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Plain text to HTML (and other formats) converter
WWW=		https://triptico.com/software/grutatxt.html

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
