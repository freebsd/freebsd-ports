PORTNAME=	kcgi
PORTVERSION=	1.0.0
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

post-install:
	cd ${STAGEDIR}${PREFIX}/lib; for i in *.so; do \
		${RLN} -s $${i}.1.1 $${i}.1 ; \
		done
.include <bsd.port.mk>
