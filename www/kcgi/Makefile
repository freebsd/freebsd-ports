# $FreeBSD$

PORTNAME=	kcgi
PORTVERSION=	0.8.4
CATEGORIES=	www devel
MASTER_SITES=	http://kristaps.bsd.lv/kcgi/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimal sandboxed CGI library in C

LICENSE=	ISCL

USES=		tar:tgz

OPTIONS_DEFINE=	EXAMPLES

BROKEN_FreeBSD_9=	Requires capsicum

HAS_CONFIGURE=	yes
MAKE_ARGS=	DATADIR=${EXAMPLESDIR}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kfcgi ${STAGEDIR}${PREFIX}/sbin/kfcgi

.include <bsd.port.mk>
