# New ports collection makefile for:   spambnc
# Date created:        25 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	spambnc
PORTVERSION=	20010310
CATEGORIES=	mail
MASTER_SITES=	http://www.spambouncer.org/
DISTFILES=	spambnc.tar.Z index.shtml
EXTRACT_ONLY=	spambnc.tar.Z

MAINTAINER=	greid@ukug.uk.freebsd.org

IGNOREFILES=	index.shtml
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SBFILES=	freemail legitlists notify procmail.rc sb-new.rc \
		sb-old.rc sb.rc spam

do-install:
	${MKDIR} ${PREFIX}/share/spambnc/
.for FILE in ${SBFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/spambnc/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/spambnc/
	${INSTALL_DATA} ${DISTDIR}/index.shtml ${PREFIX}/share/doc/spambnc/documentation.html
.endif

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
