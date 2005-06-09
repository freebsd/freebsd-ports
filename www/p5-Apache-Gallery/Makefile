# New ports collection makefile for:    p5-Apache-Gallery
# Date created:				October 24 2002
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Gallery
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	http://apachegallery.dk/download/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	kvs@pil.dk
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
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
DEPENDS_ARGS+=	WITHOUT_MODPERL=yes
DEPENDS_ARGS+=	WITH_MODPERL2=yes
.else
# XXX - probe for static mod_perl using `httpd -l | grep perl`
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
.endif

PERL_CONFIGURE=	yes

MAN3=		Apache::Gallery.3

TEMPLATEFILES=	dircomment.tpl directory.tpl error.tpl file.tpl index.tpl \
		info.tpl interval.tpl intervalactive.tpl layout.tpl \
		navpicture.tpl nodircomment.tpl nopictureinfo.tpl \
		orig.tpl picture.tpl scale.tpl pictureinfo.tpl refresh.tpl \
		scale.tpl scaleactive.tpl showpicture.tpl \
		slideshowisoff.tpl slideshowoff.tpl
ICONS=		application-doc.png application-pdf.png application-rtf.png \
		sound-mp3.png sound-ogg.png sound-wav.png \
		video-asf.png video-avi.png \
		video-mov.png video-mpeg.png video-mpg.png video-wmv.png \
		video-asf.png agfolder.png

post-patch:
	@${RM} -f ${WRKSRC}/lib/Apache/Gallery.pm.orig

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/Apache-Gallery/templates
.for f in ${TEMPLATEFILES}
	${INSTALL_DATA} ${WRKSRC}/templates/default/${f} \
		${PREFIX}/share/Apache-Gallery/templates/
.endfor
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/htdocs/${f} \
		${PREFIX}/www/icons/
.endfor
	${MKDIR} ${PREFIX}/share/Apache-Gallery/css
	${INSTALL_DATA} ${WRKSRC}/templates/default/gallery.css \
		${PREFIX}/share/Apache-Gallery/css/
.endif
.if !defined(BATCH)
	@${SED} s!%%PREFIX%%!${PREFIX}!g ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
#IGNORE=	Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
