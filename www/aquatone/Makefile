# $FreeBSD$

PORTNAME=	aquatone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	www security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for domain flyovers that checks open ports and takes screenshots

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	michenriksen
GH_TUPLE=	andybalholm:cascadia:680b6a5:cascadia/vendor/github.com/andybalholm/cascadia \
		asaskevich:EventBus:d46933a:eventbus/vendor/github.com/asaskevich/EventBus \
		fatih:color:3f9d52f:color/vendor/github.com/fatih/color \
		google:uuid:c2e93f3:uuid/vendor/github.com/google/uuid \
		lair-framework:go-nmap:3b9bafd:gonmap/vendor/github.com/lair-framework/go-nmap \
		moul:http2curl:faeffb3:http2curl/vendor/github.com/moul/http2curl \
		mvdan:xurls:20723a7:xurls/vendor/github.com/mvdan/xurls \
		parnurzeal:gorequest:b060445:gorequest/vendor/github.com/parnurzeal/gorequest \
		pkg:errors:27936f6:errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:5d4384e:godifflib/vendor/github.com/pmezard/go-difflib \
		PuerkitoBio:goquery:3dcf72e:goquery/vendor/github.com/PuerkitoBio/goquery \
		remeh:sizedwaitgroup:5e7302b:sizedwaitgroup/vendor/github.com/remeh/sizedwaitgroup \
		golang:net:161cd47:net/vendor/golang.org/x/net
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/aquatone

.include <bsd.port.mk>
