# New ports collection makefile for:   EasyPG
# Date created: 	25 December 2007
# Whom: 		Shota Iwazaki <iwazaki8@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	easypg
PORTVERSION=	0.0.16
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	epg/29289
DISTNAME=	epg-${PORTVERSION}

MAINTAINER=	iwazaki8@yahoo.co.jp
COMMENT=	EasyPG is yet another GnuPG interface for Emacs

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg1

GNU_CONFIGURE=	yes
USE_EMACS=	yes

.if defined(WITH_COMPILED_ELISP)
PLIST_SUB=	COMPILED_ELISP=""
.else
PLIST_SUB=	COMPILED_ELISP="@comment "
.endif

INFO=	epa
.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog NEWS README
.endif

do-install:
	cd ${WRKSRC};\
	${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}/epg;\
	${INSTALL_DATA} *.el ${PREFIX}/${EMACS_SITE_LISPDIR}/epg
.if defined(WITH_COMPILED_ELISP)
	cd ${WRKSRC};\
	${INSTALL_DATA} *.elc ${PREFIX}/${EMACS_SITE_LISPDIR}/epg
.endif
	cd ${WRKSRC};\
	${INSTALL_MAN} epa.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR};\
	cd ${WRKSRC};\
	${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
