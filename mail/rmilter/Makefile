# $FreeBSD$

PORTNAME=		rmilter
PORTVERSION=		1.5.43
CATEGORIES=		mail
MASTER_SITES=		http://cdn.bitbucket.org/vstakhov/rmilter/downloads/

MAINTAINER=		vsevolod@FreeBSD.org
COMMENT=		Milter that performs spamd, clamav, and spf checks

LICENSE=	BSD

PLIST_FILES=	sbin/rmilter etc/rc.d/rmilter.sh etc/rmilter.conf.sample

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
				--enable-dkim
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WITH_SENDMAIL_BASE=	yes

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=	--enable-debug
.endif

LIB_DEPENDS+=		pcre:${PORTSDIR}/devel/pcre \
			spf2:${PORTSDIR}/mail/libspf2 \
			opendkim:${PORTSDIR}/mail/opendkim

CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LIBS}

MAN8=		rmilter.8

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmilter.sh ${PREFIX}/etc/rc.d/
	${INSTALL_PROGRAM} ${WRKSRC}/rmilter ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample ${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/rmilter.8 ${MAN8PREFIX}/man/man8/

.include <bsd.port.post.mk>
