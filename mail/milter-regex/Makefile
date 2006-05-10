# New ports collection makefile for:	milter-regex
# Date created:				2003-10-03
# Whom:					trevor
#
# based on the OpenBSD port by Daniel Hartmeier (dhartmei on OpenBSD.org)
# $FreeBSD$
#

PORTNAME=	milter_regex
PORTVERSION=	1.6
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/
DISTNAME=	milter-regex-${PORTVERSION}

MAINTAINER=	dhartmei@FreeBSD.org
COMMENT=	Milter plugin to sendmail for regular expression filtering

WRKSRC=		${WRKDIR}/milter-regex
MAILUSER?=	mailnull
MAN8=		milter-regex.8
PLIST_FILES=	libexec/milter-regex
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if defined(SENDMAIL_MILTER_PORT)
.if defined(SENDMAIL_WITH_SHARED_MILTER)
LIB_DEPENDS+=	milter.3:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.endif
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if !defined(SENDMAIL_MILTER_PORT)
pre-everything::
.if !exists(/usr/lib/libmilter.a)
	${ECHO_CMD} "Fatal: milter required, see instructions in DESCR"
	${FALSE}
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e \
	    "s:/etc/milter-regex.conf:${PREFIX}/etc/milter-regex.conf:g; \
	    s:_milter-regex:${MAILUSER}:g;" ${WRKSRC}/milter-regex.c
	@${REINPLACE_CMD} -e \
	    "s:/etc/milter-regex.conf:${PREFIX}/etc/milter-regex.conf:g; \
	    s:mailstats 1:mailstats 8:;" ${WRKSRC}/milter-regex.8
	@${REINPLACE_CMD} -e "s:-lpthread:${PTHREAD_LIBS}:g; \
	    s:-I/usr/src/gnu/usr.sbin/sendmail/include:${PTHREAD_CFLAGS}:g; \
	    s:-L/usr/local/lib:-L${LOCALBASE}/lib:g; \
	    s/-Werror//g"  ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${PREFIX}/libexec
	@${INSTALL_MAN} ${WRKSRC}/milter-regex.8 ${PREFIX}/man/man8
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
