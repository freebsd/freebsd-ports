# New ports collection makefile for:   spamass-milter
# Date created:        29 April 2002
# Whom:                Eugene M. Kim <ab@astralblue.net>
#
# $FreeBSD$
#

PORTNAME=	spamass-milter
PORTVERSION=	0.1.1
CATEGORIES=	mail
MASTER_SITES=	http://freesoftware.fsf.org/download/spamass-milt/

MAINTAINER=	ab@astralblue.net

BUILD_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

.if !exists(/usr/lib/libmilter.a)
IGNORE=		requires Sendmail 8.12; upgrade the base system
.endif

USE_AUTOMAKE=	YES
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" PORT_CFLAGS="${CFLAGS}"
PLIST_SUB=	DOCSDIR=${DOCSDIR}

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
