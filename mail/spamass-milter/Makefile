# New ports collection makefile for:   spamass-milter
# Date created:        29 April 2002
# Whom:                Eugene M. Kim <ab@astralblue.net>
#
# $FreeBSD$
#

PORTNAME=	spamass-milter
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	spamass-milt

MAINTAINER=	ab@astralblue.net
COMMENT=	Sendmail Milter (mail filter) for SpamAssassin

BUILD_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

.if !exists(/usr/lib/libmilter.a)
IGNORE=		requires Sendmail 8.12; upgrade the base system
.endif

USE_AUTOCONF_VER= 253
USE_AUTOMAKE_VER= 15

MAN1=		spamass-milter.1

post-patch:
.for f in spamass-milter.sh.dist activation.txt
	${SED} -e 's|/usr/local|${PREFIX}|g' \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor

post-install:
	${INSTALL_DATA} ${WRKDIR}/spamass-milter.sh.dist \
		${PREFIX}/etc/rc.d/spamass-milter.sh.dist
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/activation.txt ${DOCSDIR}/activation.txt
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
