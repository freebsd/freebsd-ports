# New ports collection makefile for:	tinytinyhttpd
# Date created:		01 Aug 2009
# Whom:			Shinsuke Matsui <smatsui@karashi.org>
#
# $FreeBSD$
#

PORTNAME=	tinytinyhttpd
PORTVERSION=	0.0.6b
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/mattn/tinytinyhttpd/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	smatsui@karashi.org
COMMENT=	Tiny tiny httpd

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/tthttpd
PORTDOCS=	README example.conf ChangeLog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tthttpd ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/example.conf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
