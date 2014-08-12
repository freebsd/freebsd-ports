# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	openxpki-client-html-mason
PORTVERSION=	0.14.0.1
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
DISTNAME=	openxpki-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Web interface for local openxpki daemon

LICENSE=	APACHE20

BUILD_DEPENDS=	\
	p5-openxpki>=0.14:${PORTSDIR}/security/p5-openxpki \
	p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
	p5-Data-SpreadPagination>=0:${PORTSDIR}/textproc/p5-Data-SpreadPagination
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
GH_PROJECT=	openxpki
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	66ee052

USES=		gmake perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/clients/perl/OpenXPKI-Client-HTML-Mason

DEPRECATED=	security/p5-openxpki-0.15+ abandoned Mason UI technology in favor of FastCGI
EXPIRATION_DATE=	2014-09-20

pre-patch:
	(cd ${WRKSRC} && ${FIND} ./* > MANIFEST)

post-patch:
	@${REINPLACE_CMD} -e 's|..vergen --format version.|"${PORTVERSION:R}"|g' ${WRKSRC}/Makefile.PL

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/htdocs ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/eg ${STAGEDIR}${EXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/bin ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
