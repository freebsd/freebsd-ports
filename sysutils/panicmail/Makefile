PORTNAME=	panicmail
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daemonology.net/panicmail/

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Automatically report kernel panics

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	pkesh:security/pkesh

NO_BUILD=	yes

PLIST_FILES=	etc/rc.d/panicmail \
		etc/cperciva-panicmail.pem

# Pull in gdb from ports for FreeBSD versions where it's not in base
.include <bsd.port.pre.mk>
.if ${OSVERSION} > 1200028
RUN_DEPENDS+=	${LOCALBASE}/bin/gdb:devel/gdb
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/panicmail ${STAGEDIR}${PREFIX}/etc/rc.d/
	${INSTALL_DATA} ${WRKSRC}/cperciva-panicmail.pem ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.post.mk>
