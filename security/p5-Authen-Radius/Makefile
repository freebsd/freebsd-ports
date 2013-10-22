# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Authen-Radius
PORTVERSION=	0.23
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to provide simple Radius client facilities

RUN_DEPENDS=	p5-Data-HexDump>=0.02:${PORTSDIR}/devel/p5-Data-HexDump
BUILD_DEPENDS:=	${RUN_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		perl5
USE_PERL5=	configure
MAN3=		Authen::Radius.3

RADDBFILES=	dictionary \
		dictionary.ascend \
		dictionary.cisco \
		dictionary.compat \
		dictionary.livingston \
		dictionary.quintum \
		dictionary.rfc2869 \
		dictionary.shiva \
		dictionary.tunnel \
		dictionary.usr \
		dictionary.versanet \
		dictionary.xtradius

NO_STAGE=	yes
pre-configure:
	@${RM} ${WRKSRC}/install-radius-db.PL
	@${PERL} -pi -e 's|/etc/raddb|${DATADIR}|' ${WRKSRC}/Radius.pm

post-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/raddb/ && ${INSTALL_DATA} ${RADDBFILES} ${DATADIR}

.include <bsd.port.mk>
