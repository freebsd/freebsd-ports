PORTNAME=	Spreadsheet-ReadGnumeric
PORTVERSION=	0.4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read a Gnumeric file, return Spreadsheet::Read
WWW=		https://metacpan.org/dist/Spreadsheet-ReadGnumeric

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PerlIO-gzip>=0.20:archivers/p5-PerlIO-gzip \
		p5-XML-Parser-Lite>=0.722:textproc/p5-XML-Parser-Lite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
