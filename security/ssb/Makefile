PORTNAME=	ssb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	28
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SSH Server Bruteforcer
WWW=		https://github.com/kitabisa/ssb

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_PKGNAME=	ktbs.dev/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	kitabisa
GH_TUPLE=	\
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		logrusorgru:aurora:v2.0.3:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		projectdiscovery:gologger:v1.0.1:projectdiscovery_gologger/vendor/github.com/projectdiscovery/gologger \
		remeh:sizedwaitgroup:v1.0.0:remeh_sizedwaitgroup/vendor/github.com/remeh/sizedwaitgroup

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
