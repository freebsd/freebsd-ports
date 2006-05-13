# New ports collection makefile for:	rc_subr
# Date created:				July 4, 2003
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	rc_subr
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	eik

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Common startup and shutdown subroutines used by scripts

USE_BZIP2=	yes
NO_BUILD=	yes

MAN8=		rc.subr.8
PLIST_FILES=	etc/rc.subr \
		${EXAMPLESDIR:S,^${PREFIX}/,,}/README \
		${EXAMPLESDIR:S,^${PREFIX}/,,}/example.sh
PLIST_DIRS=	${EXAMPLESDIR:S,^${PREFIX}/,,}

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's, (/etc(/rc.subr| )), ${PREFIX}\1,g' \
		${WRKSRC}/rc.subr.8

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/rc.subr ${PREFIX}/etc
	@${INSTALL_MAN} ${WRKSRC}/rc.subr.8 ${MAN8PREFIX}/man/man8
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/example.sh ${EXAMPLESDIR}

.include <bsd.port.mk>
