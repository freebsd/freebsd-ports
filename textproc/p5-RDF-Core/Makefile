# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	RDF-Core
PORTVERSION=	0.51
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object oriented Perl modules for handling tasks related to RDF

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

DOCSUBDIR=	/ RDF RDF/Core RDF/Core/Enumerator RDF/Core/Model \
		RDF/Core/Storage

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
.for DOCDIR in ${DOCSUBDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${DOCDIR}/*.html	${STAGEDIR}${DOCSDIR}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
