# $FreeBSD$

PORTNAME=		rmilter
PORTVERSION=		1.6.1
CATEGORIES=		mail

MAINTAINER=		vsevolod@FreeBSD.org
COMMENT=		Milter that performs spamd, clamav, and spf checks

LICENSE=	BSD2CLAUSE

USE_GITHUB=		yes
GH_ACCOUNT=		vstakhov
GH_PROJECT=		${PORTNAME}
GH_TAG=		${PORTVERSION}
GH_COMMIT=		a8d7db5

USE_RC_SUBR=	yes
USES=	cmake:outsource bison
USE_OPENSSL=	yes

PLIST_FILES=	sbin/rmilter etc/rc.d/rmilter.sh \
				etc/rmilter.conf.sample \
				man/man8/rmilter.8.gz

CMAKE_ARGS+=	-DENABLE_SPF=ON \
				-DENABLE_DKIM=ON

WITH_SENDMAIL_BASE=	yes

LIB_DEPENDS+=		libpcre.so:${PORTSDIR}/devel/pcre \
			libspf2.so:${PORTSDIR}/mail/libspf2 \
			libopendkim.so:${PORTSDIR}/mail/opendkim

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmilter.sh ${STAGEDIR}${PREFIX}/etc/rc.d/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/rmilter ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample ${STAGEDIR}${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/doc/rmilter.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.post.mk>
