PORTNAME=	local-php-security-checker
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.3
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	GH

MAINTAINER=	einar@isnic.is
COMMENT=	Tool to check PHP composer dependencies for vulnerabilities
WWW=		https://github.com/fabpot/local-php-security-checker

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

USE_GITHUB=	yes
GH_ACCOUNT=	fabpot
GH_TUPLE=	davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		hashicorp:go-version:v1.6.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/local-php-security-checker

.include <bsd.port.mk>
