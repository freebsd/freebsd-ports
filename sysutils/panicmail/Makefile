# $FreeBSD$

PORTNAME=	panicmail
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daemonology.net/panicmail/

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Automatically report kernel panics

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	pkesh:security/pkesh

NO_BUILD=	yes

PLIST_FILES=	etc/rc.d/panicmail \
		etc/cperciva-panicmail.pem

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/panicmail ${STAGEDIR}${PREFIX}/etc/rc.d/
	${INSTALL_DATA} ${WRKSRC}/cperciva-panicmail.pem ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
