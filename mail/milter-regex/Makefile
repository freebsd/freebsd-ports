# New ports collection makefile for:	milter-regex
# Date created:				2003-10-03
# Whom:					trevor
#
# based on the OpenBSD port by Daniel Hartmeier (dhartmei on OpenBSD.org)
# $FreeBSD$
#

PORTNAME=	milter_regex
PORTVERSION=	0.8
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/
DISTNAME=	milter-regex-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Milter plugin to sendmail for regular expression filtering

MAN8=		milter-regex.8
PLIST_FILES=	libexec/milter-regex

pre-everything::
.if !exists(/usr/lib/libmilter.a)
	${ECHO_CMD} "Fatal: milter required, see instructions in DESCR"
	exit 1
.endif

post-patch:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	@${SED} -e "s:-lpthread:${PTHREAD_LIBS}:g; \
	s:-I/usr/src/gnu/usr.sbin/sendmail/include:${PTHREAD_CFLAGS}:g; \
	s/-Werror//g" < ${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${PREFIX}/libexec
	@${INSTALL_MAN} ${WRKSRC}/milter-regex.8 ${PREFIX}/man/man8
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
