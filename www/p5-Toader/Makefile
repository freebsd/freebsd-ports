# Created by: Zane C, Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Toader
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	CMS meant to be used from the terminal and integrated into a VCS for rendering static pages

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Config-Tiny>=2.14:devel/p5-Config-Tiny \
		p5-Email-MIME>=1.911:mail/p5-Email-MIME \
		p5-File-MimeInfo>=0.16:devel/p5-File-MimeInfo \
		p5-Error-Helper>=1.0.0:devel/p5-Error-Helper \
		p5-Module-List>=0.003:devel/p5-Module-List \
		p5-Text-Template>=1.46:textproc/p5-Text-Template \
		p5-Term-CallEditor>=0.61:devel/p5-Term-CallEditor \
		p5-TimeDate>=1.20:devel/p5-TimeDate \
		p5-Email-Address>=1.897:mail/p5-Email-Address \
		p5-Image-ExifTool>=9.04:graphics/p5-Image-ExifTool \
		p5-GD-Thumbnail>=1.41:graphics/p5-GD-Thumbnail \
		p5-Text-Tags>=0.04:textproc/p5-Text-Tags \
		p5-Pod-WikiDoc>=0.18:textproc/p5-Pod-WikiDoc \
		p5-Script-isAperlScript>=1.0.0:devel/p5-Script-isAperlScript

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	bin/toader-autodoc bin/toader-css bin/toader-dir \
		bin/toader-entry bin/toader-find bin/toader-gallery \
		bin/toader-ls bin/toader-migrate bin/toader-page \
		bin/toader-ra bin/toader-temp

PORTDOCS=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
