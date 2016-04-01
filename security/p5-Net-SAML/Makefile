# $FreeBSD$

PORTNAME=	Net-SAML
PORTVERSION=	1.42
CATEGORIES=	security perl5
MASTER_SITES=	http://zxid.org/ \
		CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	zxid-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for using SAML SSO

LICENSE=	APACHE20

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libzxid.so:security/zxid

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5 shebangfix tar:tgz
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${DISTNAME}/Net

PORTEXAMPLES=	zxid.pl zxidhlo.pl

SHEBANG_FILES=	../zxid.pl ../zxidhlo.pl

post-patch:
	@${REINPLACE_CMD} -e 's|hexdump|my&|' ${WRKSRC}/../errmac.h
	@${REINPLACE_CMD} -e '/INC/ s|-I\.\.|& -I${LOCALBASE}/include|; /LIBS/ s|-L\.\.|-L${LOCALBASE}/lib|; s|-ldl||' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/SAML/SAML.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/ && ${INSTALL_SCRIPT} ../zxid.pl ../zxidhlo.pl ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
