# New ports collection makefile for:   kavmilter
# Date created:                12 Jun 2003
# Whom:                        Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=	kavmilter
PORTVERSION=	0.91.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://granch.ru/pub/kavmilter/

MAINTAINER=	shelton@granch.ru
COMMENT=	Sendmail antivirus filter, based on Kaspersky Antivirus and Milter API

.if !exists(/usr/lib/libmilter.a)
IGNORE=		requires Sendmail 8.12; upgrade the base system
.endif

USE_BZIP2=	yes
USE_GETOPT_LONG=yes

MAN5=		kavmilter.5
MAN8=		kavmilter.8

CPPFLAGS=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

post-install:
	${STRIP_CMD} ${PREFIX}/libexec/kavmilter

	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/kavmilter.sh.sample ${PREFIX}/etc/rc.d/kavmilter.sh.sample
	${INSTALL_SCRIPT} -m 644 ${WRKSRC}/kavmilter.conf ${PREFIX}/etc/kavmilter.conf.sample

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README CHANGES
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
