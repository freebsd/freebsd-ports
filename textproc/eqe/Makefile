# Created by: chinsan
# $FreeBSD$

PORTNAME=	eqe
PORTVERSION=	1.3.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://rlehy.free.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX equation editor

BUILD_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		Magick++-config:${PORTSDIR}/graphics/ImageMagick

USES=		perl5 shebangfix
SHEBANG_FILES=	src/eqe src/eqedit
USE_BZIP2=	yes
USE_TEX=	tex

OPTIONS_DEFINE=	DOCS

MAKE_ARGS=	PREFIX=${PREFIX}

PORTDOCS=	TODO changelog README FAQ copyright

post-patch:
	@${REINPLACE_CMD} -e 's,^\(install:\) install-doc,\1,' \
		${WRKSRC}/Makefile

post-install:
	@pod2man ${WRKSRC}/doc/eqe.pod ${WRKSRC}/doc/eqe.1
	@pod2man ${WRKSRC}/doc/eqedit.pod ${WRKSRC}/doc/eqedit.1
	${INSTALL_MAN} ${WRKSRC}/doc/eqe.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/eqedit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
