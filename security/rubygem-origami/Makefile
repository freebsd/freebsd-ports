# $FreeBSD$

PORTNAME=	origami
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby framework to parse analyze and forge PDF documents

LICENSE=	LGPL3

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	samples/actions/launch/calc.rb \
		samples/actions/launch/winparams.rb \
		samples/actions/named/named.rb \
		samples/actions/samba/smbrelay.rb \
		samples/actions/triggerevents/trigger.rb \
		samples/actions/webbug/webbug-browser.rb \
		samples/actions/webbug/webbug-js.rb \
		samples/actions/webbug/webbug-reader.rb \
		samples/digsig/signed.rb

.include <bsd.port.mk>
