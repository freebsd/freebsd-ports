# New ports collection makefile for:    p5-Apache-Gallery
# Date created:				October 24 2002
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Gallery
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://apachegallery.dk/download/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache::Gallery - mod_perl handler to create an image gallery

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2
BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/CGI/FastTemplate.pm:${PORTSDIR}/www/p5-CGI-FastTemplate \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size
RUN_DEPENDS=	${BUILD_DEPENDS}

PKGMESSAGE=	${WRKDIR}/pkg-message
PERL_CONFIGURE=	yes

MAN3=		Apache::Gallery.3

TEMPLATEFILES=	dircomment.tpl directory.tpl error.tpl file.tpl index.tpl \
		info.tpl interval.tpl intervalactive.tpl layout.tpl \
		navpicture.tpl nodircomment.tpl nopictureinfo.tpl \
		orig.tpl picture.tpl scale.tpl pictureinfo.tpl refresh.tpl \
		scale.tpl scaleactive.tpl showpicture.tpl \
		slideshowisoff.tpl slideshowoff.tpl
ICONS=		application-doc.png application-mp3.png application-ogg.png \
		application-pdf.png application-rtf.png application-wav.png \
		gallery.css video-asf.png video-avi.png \
		video-mov.png video-mpeg.png video-mpg.png video-wmv.png

post-configure:
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' pkg-message > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/Apache-Gallery/templates
.for f in ${TEMPLATEFILES}
	${INSTALL_DATA} ${WRKSRC}/templates/${f} \
		${PREFIX}/share/Apache-Gallery/templates/
.endfor
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/htdocs/${f} \
		${PREFIX}/www/icons/
.endfor
	${INSTALL_DATA} ${WRKSRC}/htdocs/folder.png \
		${PREFIX}/www/icons/folder-apache-gallery.png
	${MKDIR} ${PREFIX}/share/Apache-Gallery/css
	${INSTALL_DATA} ${WRKSRC}/htdocs/gallery.css \
		${PREFIX}/share/Apache-Gallery/css/
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
