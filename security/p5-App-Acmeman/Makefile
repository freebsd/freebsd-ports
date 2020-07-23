# Created by: Zeus Panchenko <zeus@gnu.org.ua>
# $FreeBSD$

PORTNAME=	App-Acmeman
PORTVERSION=	3.05
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic management of ACME (Let's Encrypt) SSL certificates

LICENSE=	GPLv3+

RUN_DEPENDS=	p5-Apache-Config-Preproc>=1.04:www/p5-Apache-Config-Preproc \
		p5-Apache-Defaults>=1.02:www/p5-Apache-Defaults \
		p5-Config-Parser>=1.03:devel/p5-Config-Parser \
		p5-Crypt-OpenSSL-PKCS10>=0.16:security/p5-Crypt-OpenSSL-PKCS10 \
		p5-Crypt-OpenSSL-RSA>=0.28:security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-OpenSSL-X509>=1.804:security/p5-Crypt-OpenSSL-X509 \
		p5-DateTime-Format-Strptime>=1.42:devel/p5-DateTime-Format-Strptime \
		p5-File-BackupCopy>=1.00:sysutils/p5-File-BackupCopy \
		p5-LWP-Protocol-https>=6.04:www/p5-LWP-Protocol-https \
		p5-Net-ACME2>=0.33:net/p5-Net-ACME2 \
		p5-libwww>=6.05:www/p5-libwww

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/acmeman\.conf,${PREFIX}&,' \
		${WRKSRC}/acmeman ${WRKSRC}/lib/App/Acmeman.pm \
		${WRKSRC}/lib/App/Acmeman/Source/Default.pm

.include <bsd.port.mk>
