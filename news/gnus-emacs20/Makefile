# New ports collection makefile for:   gnus-emacs20
# Date created:        29 January 2001
# Whom:                ilya
#
# $FreeBSD$
#

PORTNAME=	gnus
PORTVERSION=	5.8.8
PORTREVISION=	5
CATEGORIES=	news mail elisp
MASTER_SITES=	ftp://ftp.monash.edu.au/pub/gnus/ \
		ftp://ftp.kreonet.re.kr/pub/tools/emacs/gnus/ \
		ftp://ftp.task.gda.pl/mirror/ftp.gnus.org/pub/gnus/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A popular newsreader for emacs20

DEPRECATED=	emacs20 and related ports are obsolete; please use a more recent version
EXPIRATION_DATE=	2007-08-19

HAS_CONFIGURE=	yes

USE_EMACS=	yes
EMACS_PORT_NAME?=emacs20

CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/gnus \
		--infodir=${INFODIR}

INFODIR=	${PREFIX}/info
INFO=		emacs-mime gnus gnus-1 gnus-2 gnus-3 message

PORTDOCDIR=	share/doc/gnus-${EMACS_PORT_NAME}
DOCS=		ChangeLog GNUS-NEWS README

PLIST_SUB+=	EMACS_PORT_NAME=${EMACS_PORT_NAME} \
		INFODIR=${INFODIR:S/${PREFIX}\///}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
INFO+=		gnus-4
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${PORTDOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR}
.endfor
.endif

.include <bsd.port.post.mk>
