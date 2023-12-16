PORTNAME=	kcgi
PORTVERSION=	0.13.3
CATEGORIES=	www devel
MASTER_SITES=	http://kristaps.bsd.lv/kcgi/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimal sandboxed CGI library in C
WWW=		https://kristaps.bsd.lv/kcgi/

LICENSE=	ISCL

USES=		compiler:c11 tar:tgz

OPTIONS_DEFINE=	EXAMPLES

HAS_CONFIGURE=	yes
MAKE_ARGS=	DATADIR=${EXAMPLESDIR} INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MANDIR=${PREFIX}/share/man
USE_RC_SUBR=	kfcgi

.include <bsd.port.mk>
