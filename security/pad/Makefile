# New ports collection makefile for:	pad
# Date created:				8 July 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	pad
PORTVERSION=	1.0.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://keyserver.kjsl.com/~jharris/distfiles/
#		http://www.lammah.com/pad/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jharris@widomaker.com
COMMENT=	A command-line utility to encrypt files

DOC_FILES=	COPYING README ChangeLog
GNU_CONFIGURE=	yes
MAN1=		pad.1
PLIST=		${WRKDIR}/pkg-plist
USE_OPENSSL=	yes

pre-install:
	${ECHO_CMD} bin/pad > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOC_FILES}
	${ECHO_CMD} share/doc/pad/$i >> ${PLIST}
.endfor
.endif
	${ECHO_CMD} "@dirrm share/doc/pad" >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pad ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pad.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
