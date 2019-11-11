# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	spambnc
DISTVERSION=	30-final
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://spamfilter.spambouncer.org/downloads/
DISTNAME=	sb-${DISTVERSION}
DIST_SUBDIR=	spambnc-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Set of procmail recipes which handle known/suspected spam

LICENSE=	GPLv2

RUN_DEPENDS=	procmail:mail/procmail		\
		gsha1sum:sysutils/coreutils

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/usr/local/sb
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PORTDOCS=	loglevels.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	${RM} -r ${STAGEDIR}${DATADIR}/docs

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/loglevels.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
