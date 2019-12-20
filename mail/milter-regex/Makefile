# Created by: trevor
# $FreeBSD$

PORTNAME=	milter-regex
PORTVERSION=	2.7
CATEGORIES=	mail
MASTER_SITES=	https://www.benzedrine.ch/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Milter plugin to sendmail for regular expression filtering

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${FILESDIR}/COPYRIGHT

USE_RC_SUBR=	milterregex
SUB_LIST=	SPOOLDIR=${SPOOLDIR}
PLIST_SUB=	SPOOLDIR=${SPOOLDIR}

MAILUSER?=	mailnull
SPOOLDIR?=	/var/run/milter-regex

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

post-patch:
	${REINPLACE_CMD} -e \
	    "s:/etc/milter-regex.conf:${PREFIX}/etc/milter-regex.conf:g; \
	    s:/var/spool/milter-regex:${SPOOLDIR}:g; \
	    s:_milter-regex:${MAILUSER}:g;" ${WRKSRC}/milter-regex.c
	${REINPLACE_CMD} -e \
	    "s:/etc/milter-regex.conf:${PREFIX}/etc/milter-regex.conf:g; \
	    s:/var/spool/milter-regex:${SPOOLDIR}:g; \
	    s:mailstats 1:mailstats 8:;" ${WRKSRC}/milter-regex.8
	${REINPLACE_CMD} -e "s:-I/usr/src/gnu/usr.sbin/sendmail/include::g; \
	    s:-L/usr/local/lib:-L${LOCALBASE}/lib:g; \
	    s/-Werror//g"  ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_MAN} ${WRKSRC}/milter-regex.8 ${STAGEDIR}${PREFIX}/man/man8/
	${MKDIR} ${STAGEDIR}${SPOOLDIR}

.include <bsd.port.post.mk>
