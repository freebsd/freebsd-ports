# New ports collection makefile for:	sks
# Date created:		2004-10-16
# Whom:			johans@stack.nl
#
# $FreeBSD$
#

PORTNAME=	sks
PORTVERSION=	1.0.9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=sks
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@stack.nl
COMMENT=	Synchronizing Key Server, a fast OpenPGP keyserver

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml
LIB_DEPENDS=	db41:${PORTSDIR}/databases/db41

USE_GPG=	yes
SIG_SUFFIX=	.sig
USE_GMAKE=	yes
MAKE_ENV=	BDBINCLUDE="-I${LOCALBASE}/include/db41" \
		BDBLIB="-L${LOCALBASE}/lib" \
		LIBDB="-ldb41" \
		MANDIR="${MANPREFIX}/man"
ALL_TARGET=	all sks.8
USE_PERL5_BUILD=	yes

PLIST_FILES=	bin/sks bin/sks_add_mail bin/sks_build.sh
MAN8=		sks.8
PORTDOCS=	ANNOUNCEMENT BUGS README TODO

post-patch:
	@${CP} ${FILESDIR}/sks.numerix.patch ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sks 	  ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sks_add_mail ${PREFIX}/bin
	${INSTALL_SCRIPT}  ${WRKSRC}/sks_build.sh ${PREFIX}/bin
	${INSTALL_MAN}     ${WRKSRC}/sks.8	  ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
