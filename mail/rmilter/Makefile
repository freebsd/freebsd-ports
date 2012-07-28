# New ports collection makefile for:	rmilter
# Date created:				2007-11-02
# Whom:					vsevolod
#
# $FreeBSD$
#

PORTNAME=		rmilter
PORTVERSION=		1.5.37
PORTREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://highsecure.ru/

MAINTAINER=		vsevolod@FreeBSD.org
COMMENT=		Milter that performs spamd, clamav, and spf checks

PLIST_FILES=	sbin/rmilter etc/rc.d/rmilter.sh etc/rmilter.conf.sample

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WITH_SENDMAIL_BASE=	yes

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=	--enable-debug
.endif

.ifdef WITH_SENDMAIL
CONFIGURE_ARGS+=	--enable-sendmail
.endif

LIB_DEPENDS+=		pcre.1:${PORTSDIR}/devel/pcre \
			spf2.3:${PORTSDIR}/mail/libspf2

CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LIBS}

MAN8=		rmilter.8

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmilter.sh ${PREFIX}/etc/rc.d/
	${INSTALL_PROGRAM} ${WRKSRC}/rmilter ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample ${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/rmilter.8 ${MAN8PREFIX}/man/man8/

.include <bsd.port.post.mk>
