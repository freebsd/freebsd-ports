# Created by: Shota Iwazaki <iwazaki8@yahoo.co.jp>
# $FreeBSD$

PORTNAME=	easypg
PORTVERSION=	0.0.16
PORTREVISION=	13
CATEGORIES=	security elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	epg/29289
DISTNAME=	epg-${PORTVERSION}

MAINTAINER=	iwazaki8@yahoo.co.jp
COMMENT=	EasyPG is yet another GnuPG interface for Emacs

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg1

GNU_CONFIGURE=	yes
USE_EMACS=	yes

OPTIONS_DEFINE=	DOCS
INFO=	epa
PORTDOCS=	ChangeLog NEWS README

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "emacs23") || (${EMACS_PORT_NAME} == "emacs24") || (${EMACS_PORT_NAME} == "emacs-devel")
IGNORE=		easyPG has been part of Emacs 23 and Emacs 24
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/epg
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc ${PREFIX}/${EMACS_SITE_LISPDIR}/epg
	${INSTALL_MAN} ${WRKSRC}/epa.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
