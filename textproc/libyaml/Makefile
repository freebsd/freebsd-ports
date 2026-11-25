PORTNAME=	libyaml
PORTVERSION=	0.2.7
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/yaml/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	yaml-${DISTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	YAML 1.1 parser and emitter written in C
WWW=		https://pyyaml.org/wiki/LibYAML

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License

USES=		cpe gmake libtool pathfix
CPE_VENDOR=	pyyaml
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

TEST_TARGET=	check

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-static

.include <bsd.port.mk>
