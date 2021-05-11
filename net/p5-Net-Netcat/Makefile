# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	Net-Netcat
PORTVERSION=	0.05
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl wrapper class for nc(1) utility (netcat)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-ErrorHandler>=0:devel/p5-Class-ErrorHandler \
		p5-IPC-Run>=0:devel/p5-IPC-Run

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_PERL_REL}/Net/Netcat.pm \
		${SITE_MAN3_REL}/Net::Netcat.3.gz

.include <bsd.port.mk>
