# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Gantry
PORTVERSION=	3.64
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web application framework for mod_perl, cgi, etc

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-Date-Calc>=0:devel/p5-Date-Calc \
		p5-CGI-Simple>=0:www/p5-CGI-Simple \
		p5-Data-FormValidator>=0:textproc/p5-Data-FormValidator \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-HTML-Prototype>=0:www/p5-HTML-Prototype \
		p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-URI>=0:net/p5-URI \
		p5-Crypt-CBC>=0:security/p5-Crypt-CBC \
		p5-Sub-Install>0:devel/p5-Sub-Install \
		p5-Mail-RFC822-Address>0:mail/p5-Mail-RFC822-Address \
		p5-Config-General>0:devel/p5-Config-General \
		p5-JSON>0:converters/p5-JSON \
		p5-Template-Toolkit>=2.0:www/p5-Template-Toolkit \
		p5-Template-Plugin-HTML-SuperForm>0:textproc/p5-Template-Plugin-HTML-SuperForm
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild
CONFIGURE_ARGS=	</dev/null
PLIST_SUB+=	WWWDIR=${WWWDIR}
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/${PORTNAME:tl}

post-patch:
	${REINPLACE_CMD} -e 's,/home/httpd/html/gantry,${WWWDIR},g' \
		-e 's,\$ENV{'GANTRY_TEMPLATE_PATH'},${WWWDIR},g' \
	    ${WRKSRC}/Build.PL

.include <bsd.port.mk>
