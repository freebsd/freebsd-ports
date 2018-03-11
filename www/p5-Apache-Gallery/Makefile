# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Apache-Gallery
PORTVERSION=	1.0.2
PORTREVISION=	5
PORTEPOCH=	3
CATEGORIES=	www perl5
MASTER_SITES=	http://apachegallery.dk/download/ \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Apache::Gallery - mod_perl handler to create an image gallery

LICENSE=	ART10

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI \
		p5-Text-Template>=0:textproc/p5-Text-Template \
		p5-Image-Info>=0:graphics/p5-Image-Info \
		p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-Image-Imlib2>=0:graphics/p5-Image-Imlib2 \
		p5-libapreq2>=0:www/p5-libapreq2 \
		p5-CGI>=0:www/p5-CGI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		apache:2.2+ perl5
USE_PERL5=	configure
NO_ARCH=	yes

DOC_FILES=	INSTALL LICENSE README TODO UPGRADE

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${CP} ${WRKSRC}/templates/bright/navdirectory.tpl ${WRKSRC}/templates/default
	@${CP} ${WRKSRC}/templates/bright/navdirectory.tpl ${WRKSRC}/templates/new

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/www/icons/gallery/
	${INSTALL_DATA} ${WRKSRC}/htdocs/* \
		${STAGEDIR}/${PREFIX}/www/icons/gallery/
	@${MKDIR} ${STAGEDIR}/${DATADIR}/templates/bright
	@${MKDIR} ${STAGEDIR}/${DATADIR}/templates/default
	@${MKDIR} ${STAGEDIR}/${DATADIR}/templates/new
	${INSTALL_DATA} ${WRKSRC}/templates/bright/* \
		${STAGEDIR}/${DATADIR}/templates/bright/
	${INSTALL_DATA} ${WRKSRC}/templates/default/* \
		${STAGEDIR}/${DATADIR}/templates/default/
	${INSTALL_DATA} ${WRKSRC}/templates/new/* \
		${STAGEDIR}/${DATADIR}/templates/new/
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.post.mk>
