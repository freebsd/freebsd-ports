# New ports collection makefile for:    p5-Authen-Radius
# Date created:				September 11th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Radius
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-
DISTNAME=	RadiusPerl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl5 module to provide simple Radius client facilities

BUILD_DEPENDS=	${SITE_PERL}/Data/HexDump.pm:${PORTSDIR}/devel/p5-Data-HexDump
RUN_DEPENDS=	${SITE_PERL}/Data/HexDump.pm:${PORTSDIR}/devel/p5-Data-HexDump

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PERL_CONFIGURE=	yes
MAN3=		Authen::Radius.3

RADDBFILES=	dictionary \
		dictionary.ascend \
		dictionary.cisco \
		dictionary.compat \
		dictionary.livingston \
		dictionary.quintum \
		dictionary.shiva \
		dictionary.tunnel \
		dictionary.usr \
		dictionary.versanet \
		dictionary.xtradius

.include <bsd.port.pre.mk>

pre-configure:
	@${RM} ${WRKSRC}/install-radius-db.PL
	@${PERL} -pi -e 's|/etc/raddb|${DATADIR}|' ${WRKSRC}/Radius.pm

post-install:
	@${MKDIR} ${DATADIR}
.for FILE in ${RADDBFILES}
	@${INSTALL_DATA} ${WRKSRC}/raddb/${FILE} ${DATADIR}/${FILE}
.endfor

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO.pm:${PORTSDIR}/devel/p5-IO
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO.pm:${PORTSDIR}/devel/p5-IO
.endif

.include <bsd.port.post.mk>
