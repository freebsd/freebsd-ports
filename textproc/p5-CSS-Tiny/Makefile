# New ports collection makefile for:	p5-CSS-Tiny
# Date created:		2003-10-31
# Whom:			Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	CSS-Tiny
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CSS
PKGNAMEPREFIX=	p5-

MAINTAINER=	hansjoerg.pehofer@uibk.ac.at
COMMENT=	Read/Write .css files with as little code as possible

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		CSS::Tiny.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
EXTRA_PATCHES=	${PATCHDIR}/500503-lib::CSS::Tiny.pm
.endif

post-patch:
	@${RM} ${WRKSRC}/inc/Module/Install/AutoInstall.pm
	@${PERL} -pi -e '$$_="" if /AutoInstall/' ${WRKSRC}/MANIFEST
	@${PERL} -pi -e '$$_="" if /Test::More|auto_install/' ${WRKSRC}/Makefile.PL
.if ${PERL_LEVEL} <= 500503
	@${RM} ${WRKSRC}/lib/CSS/Tiny.pm.orig
.endif

.include <bsd.port.post.mk>
