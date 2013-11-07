# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Spreadsheet-WriteExcel
PORTVERSION=	2.39
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write to a cross-platform Excel binary file

BUILD_DEPENDS=	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-OLE-Storage_Lite>=0:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	"*.p[lm]"

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tpj_images
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/tpj_images/* ${STAGEDIR}${DOCSDIR}/tpj_images
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README \
		${WRKSRC}/examples/republic.png ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.txt ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
