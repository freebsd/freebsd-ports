# Created by: arved
# $FreeBSD$

PORTNAME=	llgal
PORTVERSION=	0.13.17
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.gna.org/llgal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line online gallery generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool
RUN_DEPENDS=	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
		convert:${PORTSDIR}/graphics/ImageMagick

USES=		gettext perl5 gmake tar:bzip2

MAN1=		llgal.1
MAN5=		llgalrc.5

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,^PREFIX,#PREFIX," ${WRKSRC}/Makefile

post-configure:
	${SED} -e "s,@VERSION@,${PORTVERSION}," < ${WRKSRC}/lib/Makefile.PL.in > ${WRKSRC}/lib/Makefile.PL
	cd ${WRKSRC}/lib; ${PERL} Makefile.PL
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install//' ${WRKSRC}/lib/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/llgal.1 ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/llgalrc.5 ${MAN5PREFIX}/man/man5
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/llgalrc ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} examples ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
