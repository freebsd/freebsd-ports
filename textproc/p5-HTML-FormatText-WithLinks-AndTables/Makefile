# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-FormatText-WithLinks-AndTables
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to convert HTML to text with tables in tact

BUILD_DEPENDS=	p5-HTML-FormatText-WithLinks>=0:${PORTSDIR}/textproc/p5-HTML-FormatText-WithLinks \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
