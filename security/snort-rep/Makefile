PORTNAME=	snort-rep
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://david.schweikert.ch/software/snort-rep/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Snort reporting tool that can produce text or HTML from logs

USES=		shebangfix perl5
SHEBANG_FILES=	snort-rep snort-rep-mail

OPTIONS_DEFINE=	EXAMPLES

do-build:
	(cd ${BUILD_WRKSRC} ; pod2man --lax snort-rep > snort-rep.1)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snort-rep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/snort-rep.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/snort-rep-mail ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
