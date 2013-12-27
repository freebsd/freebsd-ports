# $FreeBSD$

PORTNAME=		rmilter
PORTVERSION=		1.5.47
CATEGORIES=		mail

MAINTAINER=		vsevolod@FreeBSD.org
COMMENT=		Milter that performs spamd, clamav, and spf checks

LICENSE=	BSD2CLAUSE

USE_GITHUB=		yes
GH_ACCOUNT=		vstakhov
GH_PROJECT=		${PORTNAME}
GH_TAG=		${PORTVERSION}
GH_COMMIT=		3d7b91c

USE_RC_SUBR=	yes

PLIST_FILES=	sbin/rmilter etc/rc.d/rmilter.sh \
				etc/rmilter.conf.sample \
				man/man8/rmilter.8.gz

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
				--enable-dkim
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WITH_SENDMAIL_BASE=	yes

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=	--enable-debug
.endif

LIB_DEPENDS+=		libpcre.so:${PORTSDIR}/devel/pcre \
			libspf2.so:${PORTSDIR}/mail/libspf2 \
			libopendkim.so:${PORTSDIR}/mail/opendkim

CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LIBS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmilter.sh ${STAGEDIR}${PREFIX}/etc/rc.d/
	${INSTALL_PROGRAM} ${WRKSRC}/rmilter ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample ${STAGEDIR}${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/rmilter.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.post.mk>
