# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Apache-Gallery
PORTVERSION=	1.0.2
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	www perl5
MASTER_SITES=	http://apachegallery.dk/download/ \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Apache::Gallery - mod_perl handler to create an image gallery

LICENSE=	ART10

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-Image-Info>=0:${PORTSDIR}/graphics/p5-Image-Info \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-Image-Imlib2>=0:${PORTSDIR}/graphics/p5-Image-Imlib2 \
		p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2 \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_APACHE=	22+

PLIST_DIRSTRY+=	www/icons

MAN3=		Apache::Gallery.3
DOC_FILES=	INSTALL LICENSE README TODO UPGRADE

SUB_FILES+=	pkg-message

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}/
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}/${DOCSDIR}/
.endfor
.endif

.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
