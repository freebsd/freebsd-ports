# $FreeBSD$

PORTNAME=	rmilter
PORTVERSION=	1.8.6
CATEGORIES=	mail

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Milter that performs rspamd, clamav, and other checks

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libopendkim.so:mail/opendkim \
		libmemcached.so:databases/libmemcached

USE_GITHUB=	yes
GH_ACCOUNT=	vstakhov

USES=		cmake:outsource bison
USE_OPENSSL=	yes

USERS=		_rmilter
GROUPS=		_rmilter

CMAKE_ARGS+=	-DENABLE_DKIM=ON

WITH_SENDMAIL_BASE=	yes

.include <bsd.port.pre.mk>

# Workaround to prevent bsd.milter.mk from breaking the build with the recent clang
WITHOUT_MILTER_LDFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

post-patch:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/freebsd/rmilter > ${WRKDIR}/rmilter

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rmilter ${STAGEDIR}${PREFIX}/etc/rc.d/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/rmilter ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample ${STAGEDIR}${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/doc/rmilter.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

post-stage:
	${INSTALL} -d ${STAGEDIR}/var/run/rmilter
.include <bsd.port.post.mk>
