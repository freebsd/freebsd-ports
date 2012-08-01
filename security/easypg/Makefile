# New ports collection makefile for:   EasyPG
# Date created: 	25 December 2007
# Whom: 		Shota Iwazaki <iwazaki8@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	easypg
PORTVERSION=	0.0.16
PORTREVISION=	9
CATEGORIES=	security elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	epg/29289
DISTNAME=	epg-${PORTVERSION}

MAINTAINER=	iwazaki8@yahoo.co.jp
COMMENT=	EasyPG is yet another GnuPG interface for Emacs

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg1

GNU_CONFIGURE=	yes
USE_EMACS=	yes

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "emacs23")
IGNORE=		easyPG has been part of Emacs 23
.endif

INFO=	epa
.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog NEWS README
.endif

do-install:
	cd ${WRKSRC};\
	${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}/epg;\
	${INSTALL_DATA} *.el *.elc ${PREFIX}/${EMACS_SITE_LISPDIR}/epg
	cd ${WRKSRC};\
	${INSTALL_MAN} epa.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR};\
	cd ${WRKSRC};\
	${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
