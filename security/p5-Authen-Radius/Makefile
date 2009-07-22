# New ports collection makefile for:    p5-Authen-Radius
# Date created:				September 11th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Radius
PORTVERSION=	0.13
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
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

pre-configure:
	@${RM} ${WRKSRC}/install-radius-db.PL
	@${PERL} -pi -e 's|/etc/raddb|${DATADIR}|' ${WRKSRC}/Radius.pm

post-install:
	@${MKDIR} ${DATADIR}
.for FILE in ${RADDBFILES}
	@${INSTALL_DATA} ${WRKSRC}/raddb/${FILE} ${DATADIR}/${FILE}
.endfor

.include <bsd.port.mk>
