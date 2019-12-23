# Created by: Zeus Panchenko <zeus@gnu.org.ua>
# $FreeBSD$

PORTNAME=	App-Acmeman
PORTVERSION=	3.02
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic management of ACME (Let's Encrypt) SSL certificates

LICENSE=	GPLv3+

RUN_DEPENDS=	p5-Apache-Config-Preproc>=1.03:www/p5-Apache-Config-Preproc \
		p5-Apache-Defaults>=1.02:www/p5-Apache-Defaults \
		p5-Config-Parser>=1.03:devel/p5-Config-Parser \
		p5-Crypt-OpenSSL-PKCS10>=0.16:security/p5-Crypt-OpenSSL-PKCS10 \
		p5-Crypt-OpenSSL-X509>=1.804:security/p5-Crypt-OpenSSL-X509 \
		p5-DateTime-Format-Strptime>=1.42:devel/p5-DateTime-Format-Strptime \
		p5-LWP-Protocol-https>=6.04:www/p5-LWP-Protocol-https \
		p5-Net-ACME2>=0.33:net/p5-Net-ACME2 \
		p5-libwww>=6.05:www/p5-libwww

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-extract:
	@${CP} ${FILESDIR}/Unconfigured.pm ${WRKSRC}/lib/App/Acmeman/Source

post-patch:
	@${REINPLACE_CMD} -e '/config_file =/s,/etc,${PREFIX}&,' \
		${WRKSRC}/lib/App/Acmeman.pm

post-stage:
	@${PRINTF} "[core]\n\tsource = unconfigured\n" > \
		${STAGEDIR}${PREFIX}/etc/acmeman.conf.sample

.include <bsd.port.mk>
