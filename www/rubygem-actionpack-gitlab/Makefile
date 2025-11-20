PORTNAME=	actionpack
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/actionpack \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview-gitlab \
		rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-cgi>=0:www/rubygem-cgi \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri \
		rubygem-racc>=0:devel/rubygem-racc \
		rubygem-rack22>=2.2.4,3:www/rubygem-rack22 \
		rubygem-rack-session10>=1.0.1:www/rubygem-rack-session10 \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-rails-dom-testing-rails-gitlab>=2.2<3:textproc/rubygem-rails-dom-testing-rails-gitlab \
		rubygem-rails-html-sanitizer>=1.6<2:textproc/rubygem-rails-html-sanitizer

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
