# $FreeBSD$

PORTNAME=	smtp
PORTVERSION=	3.6
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.logix.cz/michal/devel/smtp-cli/
PKGNAMESUFFIX=	-cli
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}
EXTRACT_SUFX=	-${PORTVERSION}

MAINTAINER=	fw@moov.de
COMMENT=	Powerful SMTP command line client

LICENSE=	GPLv3

USES=		shebangfix

RUN_DEPENDS=	p5-Digest-HMAC>0:security/p5-Digest-HMAC \
		p5-File-LibMagic>0:devel/p5-File-LibMagic \
		p5-IO-Socket-SSL>0:security/p5-IO-Socket-SSL \
		p5-MIME-Lite>0:mail/p5-MIME-Lite \
		p5-Term-ReadKey>0:devel/p5-Term-ReadKey

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/smtp-cli
SHEBANG_FILES=	smtp-cli

do-extract:
	@${MKDIR} ${WRKSRC}/
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
