PORTNAME=	HTTP-MHTTP
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Low level access to the HTTP protocol
WWW=		https://metacpan.org/release/HTTP-MHTTP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 ssl
USE_PERL5=	configure patch

CONFIGURE_ARGS=	--default
CONFIGURE_ENV=	GOTSSL=yes

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${PERL} -pi -e 's!(?<=POSSIBLE_SSL_DIRS = qw\().*(?=\);)!${OPENSSLBASE}!;' \
		${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/HTTP/MHTTP/MHTTP.so

.include <bsd.port.post.mk>
