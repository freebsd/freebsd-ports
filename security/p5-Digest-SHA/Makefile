# Ports collection makefile for:	p5-Digest-SHA
# Date created:			Aug 4, 2005
# Whom:				Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Digest-SHA
PORTVERSION=	5.61
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSHELOR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for SHA-1/224/256/384/512

PERL_CONFIGURE=	yes

MAN3=	Digest::SHA.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501000
PLIST_SUB+=	EXE_FILES="@comment "
.else
PLIST_SUB+=	EXE_FILES=""
MAN1=		shasum.1
.endif

post-patch:
.if ${PERL_LEVEL} >= 501000
	@${REINPLACE_CMD} -e 's/5.010/5.666/; /EXE_FILES/d' ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
