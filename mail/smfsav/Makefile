# New ports collection makefile for:	smfsav
# Date created:				17 February 2008
# Whom:					Anton Lysenok <bart@tapolsky.net.ua>
#
# $FreeBSD$
#

PORTNAME=	smfsav
PORTVERSION=	1.4.0
CATEGORIES=	mail
MASTER_SITES=	SF/smfs/smf-sav/smf-sav-${PORTVERSION}:0 \
		${MASTER_SITE_ISC}:1
MASTER_SITE_SUBDIR=	smfs/:0 \
		bind8/src/8.4.7/:1
DISTNAME=	smf-sav-1.4.0
DISTFILES=	smf-sav-1.4.0.tar.gz:0 \
		bind-src.tar.gz:1
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bart@tapolsky.net.ua
COMMENT=	Sendmail Sender Address Validator

PLIST_FILES=	sbin/smfsav \
		etc/smfsav.conf-dist

.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%PORTDOCS%%%%DOCSDIR%%/COPYING \
		%%PORTDOCS%%%%DOCSDIR%%/CHANGES \
		%%PORTDOCS%%%%DOCSDIR%%/README
PLIST_DIRS=	share/doc/${PORTNAME}
.endif

USE_RC_SUBR=	smfsav

SUB_FILES=	pkg-message

pre-build:
	@${ECHO}
	@${ECHO} [*] Compiling BIND 8 to make SmfSav able to resolve DNS names
	${MAKE} all -C ${WRKDIR}/src
	@${ECHO}
	@${ECHO} [*] Compiling SmfSav

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smf-sav ${PREFIX}/sbin/smfsav
	${INSTALL_DATA} ${WRKSRC}/smf-sav.conf ${PREFIX}/etc/smfsav.conf-dist

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}/CHANGES
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}/README
.endif

	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
