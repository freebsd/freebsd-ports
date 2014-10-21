# Created by: gahr
# $FreeBSD$

PORTNAME=	mbox2imap
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	http://people.cs.uchicago.edu/~brendan/scripts/ \
		http://people.freebsd.org/~gahr/distfiles/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Upload email stored in mbox file format to an IMAP server

USES=		python
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	${CP} ${DISTDIR}/${PORTNAME} ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
