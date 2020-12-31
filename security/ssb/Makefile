# $FreeBSD$

PORTNAME=	ssb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.2
CATEGORIES=	security

MAINTAINER=	neel@neelc.org
COMMENT=	SSH Server Bruteforcer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_PKGNAME=	ktbs.dev/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	kitabisa
GH_TUPLE=	\
		briandowns:spinner:v1.12.0:briandowns_spinner/vendor/github.com/briandowns/spinner \
		gernest:wow:v0.1.0:gernest_wow/vendor/github.com/gernest/wow \
		golang:crypto:9d1352758620:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		logrusorgru:aurora:v2.0.3:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		projectdiscovery:gologger:v1.0.1:projectdiscovery_gologger/vendor/github.com/projectdiscovery/gologger \
		remeh:sizedwaitgroup:v1.0.0:remeh_sizedwaitgroup/vendor/github.com/remeh/sizedwaitgroup \
		tj:go-spin:v1.1.0:tj_go_spin/vendor/github.com/tj/go-spin \
		zenthangplus:goccm:39e9e08b694a:zenthangplus_goccm/vendor/github.com/zenthangplus/goccm

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
