PORTNAME=	libwhisker
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	SF/whisker/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	se@FreeBSD.org
COMMENT=	Perl module to create HTTP test scripts

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	scripts/api_demo.pl scripts/crawl_demo.pl \
		scripts/prox.pl scripts/simple_demo.pl

PLIST_FILES=	%%SITE_PERL%%/LW2.pm \
		%%PERL5_MAN3%%/LW2.3pm.gz

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -i '' -e '1s|#!perl|${perl_CMD}|' ${WRKSRC}/scripts/form_demo[12].pl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/man/man3
	cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${PERL5} Makefile.pl install
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/scripts
	cd ${WRKSRC} && ${INSTALL_DATA} README CHANGES KNOWNBUGS ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/docs
	cd ${WRKSRC}/scripts/ && ${INSTALL_SCRIPT} * ${STAGEDIR}${DOCSDIR}/scripts

.include <bsd.port.mk>
