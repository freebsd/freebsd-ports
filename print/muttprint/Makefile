# New ports collection makefile for:   muttprint
# Date created:        11 november 2001
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	muttprint
PORTVERSION=	0.63
CATEGORIES=	print mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	muttprint

MAINTAINER=	obraun@FreeBSD.org

.if !defined(PAPERSIZE)
PAPERSIZE=	letter
.endif

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		psnup:${PORTSDIR}/print/psutils-${PAPERSIZE} \
		uncompface:${PORTSDIR}/mail/faces \
		convert:${PORTSDIR}/graphics/ImageMagick \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

MAN1=		muttprint.1
MANCOMPRESSED=	yes
USE_GMAKE=	yes

post-patch:
	-${RM} -f ${WRKSRC}/pics/*.orig

.if !defined(NOPORTDOCS)
INSTALL_TARGET=install-with-doc
.endif

.include <bsd.port.mk>
