# New ports collection makefile for:    p5-Apache-Gallery
# Date created:				October 24 2002
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Gallery
PORTVERSION=	1.0.r3
PORTEPOCH=	2
CATEGORIES=	www perl5
MASTER_SITES=	http://apachegallery.dk/download/ \
		CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r3//}RC3

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Apache::Gallery - mod_perl handler to create an image gallery

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT} \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/${PERL_ARCH}/Image/Imlib2.pm:${PORTSDIR}/graphics/p5-Image-Imlib2 \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(WITH_APACHE2)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
DEPENDS_ARGS+=	WITHOUT_MODPERL=yes
DEPENDS_ARGS+=	WITH_MODPERL2=yes
.else
# XXX - probe for static mod_perl using `httpd -l | grep perl`
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
.endif

PERL_CONFIGURE=	yes
APACHE_COMPAT=	yes

MAN3=		Apache::Gallery.3
DOC_FILES=	INSTALL LICENSE README TODO UPGRADE

post-install:
	@${MKDIR} ${PREFIX}/www/icons/gallery/
	${INSTALL_DATA} ${WRKSRC}/htdocs/* \
		${PREFIX}/www/icons/gallery/
	@${MKDIR} ${DATADIR}/templates/default
	@${MKDIR} ${DATADIR}/templates/new
	${INSTALL_DATA} ${WRKSRC}/templates/default/* \
		${DATADIR}/templates/default/
	${INSTALL_DATA} ${WRKSRC}/templates/new/* \
		${DATADIR}/templates/new/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/
.endfor
.endif

.if !defined(BATCH)
	@${SED} s!%%DATADIR%%!${DATADIR}!g ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
