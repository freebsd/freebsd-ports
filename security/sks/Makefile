# New ports collection makefile for:	sks
# Date created:		2004-10-16
# Whom:			johans@stack.nl
#
# $FreeBSD$
#

PORTNAME=	sks
PORTVERSION=	1.1.1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@stack.nl
COMMENT=	Synchronizing Key Server, a fast OpenPGP keyserver

PROJECTHOST=	sks-keyserver

USE_OCAML=	yes
USE_BDB=	46+
USE_PERL5_BUILD=yes

USE_GMAKE=	yes
MAKE_ENV=	BDBINCLUDE="-I${BDB_INCLUDE_DIR}" \
		BDBLIB="-L${BDB_LIB_DIR}" \
		LIBDB="-l${BDB_LIB_NAME}" \
		MANDIR="${MANPREFIX}/man"

PLIST_FILES=	bin/sks bin/sks_add_mail bin/sks_build.sh
MAN8=		sks.8
MANCOMPRESSED=	yes
PORTDOCS=	BUGS README TODO

post-extract:
	@: > ${WRKSRC}/Makefile.local

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
