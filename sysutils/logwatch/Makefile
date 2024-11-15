PORTNAME=	logwatch
DISTVERSION=	7.11
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	trashcan@ellael.org
COMMENT=	Log file analysis program
WWW=		https://www.logwatch.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5 shebangfix
USE_PERL5=	run
RUN_DEPENDS=	p5-HTML-HTML5-Entities>=0:textproc/p5-HTML-HTML5-Entities
SHEBANG_FILES=	scripts/logwatch.pl
PORTDOCS=	HOWTO-Customize-LogWatch README
NO_BUILD=	yes
NO_ARCH=	yes
MAKE_ENV+=	SITE_PERL_REL=${SITE_PERL_REL}
OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD}  -E \
	-e "s,/usr/share/logwatch,${LOCALBASE}," \
	-e "s,/etc/logwatch,${ETCDIR}," \
	-e "s,.BaseDir/lib,${LIBEXECDIR}," \
	-e "s,BaseDir/scripts/([^/]*)/,BaseDir/libexec/${PORTNAME}/defaults/\1/," \
	-e "s,ConfigDir/scripts/([^/]*)/,BaseDir/libexec/${PORTNAME}/\1/," \
	${WRKSRC}/scripts/logwatch.pl
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HOWTO-Customize-LogWatch ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
