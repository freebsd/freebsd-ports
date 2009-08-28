# New ports collection makefile for:	eqe
# Date created:				2007/02/13
# Whom:					chinsan
#
# $FreeBSD$

PORTNAME=	eqe
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://rlehy.free.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX equation editor

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		Magick++-config:${PORTSDIR}/graphics/ImageMagick \
		tex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base

USE_BZIP2=	yes
USE_PERL5=	yes

MAKE_ARGS=	PREFIX=${PREFIX}

MAN1=		eqe.1 eqedit.1

.if !defined(NOPORTDOCS)
PORTDOCS=	TODO changelog README FAQ copyright
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^\(install:\) install-doc,\1,' \
		${WRKSRC}/Makefile

post-install:
	@pod2man ${WRKSRC}/doc/eqe.pod ${WRKSRC}/doc/eqe.1
	@pod2man ${WRKSRC}/doc/eqedit.pod ${WRKSRC}/doc/eqedit.1
	${INSTALL_MAN} ${WRKSRC}/doc/eqe.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/eqedit.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
