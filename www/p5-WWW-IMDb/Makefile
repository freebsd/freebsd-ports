PORTNAME=	IMDb
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	http://freebsdcluster.org/~mich/software/
PKGNAMEPREFIX=	p5-WWW-
DISTNAME=	IMDb-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to query the Internet Movie Database(IMDb)

LICENSE=	GPLv2+

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
