# New ports collection makefile for:	milter-regex
# Date created:				2003-10-03
# Whom:					trevor
#
# based on the OpenBSD port by Daniel Hartmeier (dhartmei on OpenBSD.org)
# $FreeBSD$
#

PORTNAME=	milter_regex
PORTVERSION=	1.5
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/
DISTNAME=	milter-regex-${PORTVERSION}

MAINTAINER=	dhartmei@FreeBSD.org
COMMENT=	Milter plugin to sendmail for regular expression filtering

USE_REINPLACE=	yes
MAILUSER?=	mailnull
MAN8=		milter-regex.8
PLIST_FILES=	libexec/milter-regex

pre-everything::
.if !exists(/usr/lib/libmilter.a)
	${ECHO_CMD} "Fatal: milter required, see instructions in DESCR"
	exit 1
.endif

post-patch:
	@${REINPLACE_CMD} -e \
	    "s:/etc/milter-regex.conf:/usr/local/etc/milter-regex.conf:g; \
	    s:_milter-regex:${MAILUSER}:g;" ${WRKSRC}/milter-regex.c
	@${REINPLACE_CMD} -e \
	    "s:/etc/milter-regex.conf:/usr/local/etc/milter-regex.conf:g; \
	    s:mailstats 1:mailstats 8:;" ${WRKSRC}/milter-regex.8
	@${REINPLACE_CMD} -e "s:-lpthread:${PTHREAD_LIBS}:g; \
	    s:-I/usr/src/gnu/usr.sbin/sendmail/include:${PTHREAD_CFLAGS}:g; \
	    s/-Werror//g"  ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${PREFIX}/libexec
	@${INSTALL_MAN} ${WRKSRC}/milter-regex.8 ${PREFIX}/man/man8
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
