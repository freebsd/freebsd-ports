# New ports collection makefile for:    p5-Apache-Gallery
# Date created:				October 24 2002
# Whom:	      				Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Apache-Gallery
PORTVERSION=	0.5.1
CATEGORIES=	www perl5
MASTER_SITES=	http://apachegallery.dk/download/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2
BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/CGI/FastTemplate.pm:${PORTSDIR}/www/p5-CGI-FastTemplate \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PKGMESSAGE=	${WRKDIR}/pkg-message
PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::Gallery.3

TEMPLATES=	directory.tpl error.tpl index.tpl info.tpl layout.tpl \
		movie.tpl navpicture.tpl orig.tpl picture.tpl scale.tpl \
		showpicture.tpl
ICONS=		folder.png video-avi.png video-asf.png video-mov.png \
		video-mpeg.png video-mpg.png

post-configure:
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' pkg-message > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/Apache-Gallery/templates
.for f in ${TEMPLATES}
	${INSTALL_DATA} ${WRKSRC}/templates/${f} \
		${PREFIX}/share/Apache-Gallery/templates/
.endfor
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/htdocs/${f} \
		${PREFIX}/www/icons/
.endfor
	${MKDIR} ${PREFIX}/share/Apache-Gallery/css
	${INSTALL_DATA} ${WRKSRC}/htdocs/gallery.css \
		${PREFIX}/share/Apache-Gallery/css/
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
