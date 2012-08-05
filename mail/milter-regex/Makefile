# New ports collection makefile for:	milter-regex
# Date created:				2003-10-03
# Whom:					trevor
#
# based on the OpenBSD port by Daniel Hartmeier (dhartmei on OpenBSD.org)
# $FreeBSD$
#

PORTNAME=	milter-regex
PORTVERSION=	1.9
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Milter plugin to sendmail for regular expression filtering

LICENSE=	BSD
LICENSE_FILE=	${FILESDIR}/COPYRIGHT

MAILUSER?=	mailnull
MAN8=		milter-regex.8
PLIST_FILES=	libexec/milter-regex
USE_RC_SUBR=	milterregex
SPOOLDIR?=	/var/run/milter-regex
SUB_LIST=	SPOOLDIR=${SPOOLDIR}

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

post-patch:
	@${REINPLACE_CMD} -e \
	    "s:/etc/milter-regex.conf:${PREFIX}/etc/milter-regex.conf:g; \
	    s:/var/spool/milter-regex:${SPOOLDIR}:g; \
	    s:_milter-regex:${MAILUSER}:g;" ${WRKSRC}/milter-regex.c
	@${REINPLACE_CMD} -e \
	    "s:/etc/milter-regex.conf:${PREFIX}/etc/milter-regex.conf:g; \
	    s:/var/spool/milter-regex:${SPOOLDIR}:g; \
	    s:mailstats 1:mailstats 8:;" ${WRKSRC}/milter-regex.8
	@${REINPLACE_CMD} -e "s:-lpthread:${PTHREAD_LIBS}:g; \
	    s:-I/usr/src/gnu/usr.sbin/sendmail/include:${PTHREAD_CFLAGS}:g; \
	    s:-L/usr/local/lib:-L${LOCALBASE}/lib:g; \
	    s/-Werror//g"  ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${PREFIX}/libexec
	@${INSTALL_MAN} ${WRKSRC}/milter-regex.8 ${PREFIX}/man/man8
	@${INSTALL} -d -o ${MAILUSER} -g daemon -m 0700 ${SPOOLDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
