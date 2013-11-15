# Created by: Zane C, Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Toader
PORTVERSION=	1.1.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A CMS meant to be used from the terminal and integrated into a VCS for rendering static pages

RUN_DEPENDS=	p5-Config-Tiny>=2.14:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Email-MIME>=1.911:${PORTSDIR}/mail/p5-Email-MIME \
		p5-File-MimeInfo>=0.16:${PORTSDIR}/devel/p5-File-MimeInfo \
		p5-Error-Helper>=1.0.0:${PORTSDIR}/devel/p5-Error-Helper \
		p5-Module-List>=0.003:${PORTSDIR}/devel/p5-Module-List \
		p5-Text-Template>=1.46:${PORTSDIR}/textproc/p5-Text-Template \
		p5-Term-CallEditor>=0.61:${PORTSDIR}/devel/p5-Term-CallEditor \
		p5-File-Path>=2.09:${PORTSDIR}/devel/p5-File-Path \
		p5-Time-HiRes>=1.9725:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-TimeDate>=1.20:${PORTSDIR}/devel/p5-TimeDate \
		p5-Email-Address>=1.89.7:${PORTSDIR}/mail/p5-Email-Address \
		p5-Pod-Simple>=3.26:${PORTSDIR}/textproc/p5-Pod-Simple \
		p5-File-Temp>=0.22:${PORTSDIR}/devel/p5-File-Temp \
		p5-Image-ExifTool>=9.04:${PORTSDIR}/graphics/p5-Image-ExifTool \
		p5-GD-Thumbnail>=1.41:${PORTSDIR}/graphics/p5-GD-Thumbnail \
		p5-Text-Tags>=0.04:${PORTSDIR}/textproc/p5-Text-Tags \
		p5-Pod-WikiDoc>=0.18:${PORTSDIR}/textproc/p5-Pod-WikiDoc \
		p5-Script-isAperlScript>=1.0.0:${PORTSDIR}/devel/p5-Script-isAperlScript

OPTIONS_DEFINE=	DOCS

USES=	perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	bin/toader-autodoc bin/toader-css bin/toader-dir \
		bin/toader-entry bin/toader-find bin/toader-gallery \
		bin/toader-ls bin/toader-migrate bin/toader-page \
		bin/toader-ra bin/toader-temp

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
