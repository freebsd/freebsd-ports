# $FreeBSD$

PORTNAME=	Net-SAML
PORTVERSION=	1.18
CATEGORIES=	security perl5
MASTER_SITES=	http://zxid.org/ \
		CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	zxid-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for using SAML SSO

LICENSE=	APACHE20

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libzxid.so:${PORTSDIR}/security/zxid

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5 shebangfix
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${DISTNAME}/Net

SHEBANG_FILES=	../zxid.pl ../zxidhlo.pl

post-patch:
	@${REINPLACE_CMD} -e 's|hexdump|my&|' ${WRKSRC}/../errmac.h
	@${REINPLACE_CMD} -e 's|/apps/openssl/std|${LOCALBASE}|' ${WRKSRC}/Makefile.PL

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/ && ${INSTALL_SCRIPT} ../zxid.pl ../zxidhlo.pl ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
