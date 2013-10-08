# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	podlators
PORTVERSION=	2.5.3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules to convert and parse POD (Plain Old Documentation)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
PLIST_SUB+=	PERL5_12=""
.else
PLIST_SUB+=	PERL5_12="@comment "
.endif

post-patch:
.if ${PERL_LEVEL} < 501400
	@${REINPLACE_CMD} -e '/pod2text/d; s/man1pod.*pod2man.*//' ${WRKSRC}/Makefile.PL
.else
	@${REINPLACE_CMD} -e "/man1pod (/d; /EXE_FILES/d" ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
