# New ports collection makefile for:	oath-toolkit
# Date created:			23 Nov 2011
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oath-toolkit
PORTVERSION=	1.12.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Library, tools, and PAM module for OATH authentication

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes

MAN1=		oathtool.1

DOCS=		AUTHORS ChangeLog NEWS README

PORTDOCS=	*

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} 's|install-data-am: install-data-local|install-data-am:|' \
		${WRKSRC}/liboath/gtk-doc/Makefile.in
.else
	@${REINPLACE_CMD} 's|@HTML_DIR@|${DOCSDIR}|' \
		${WRKSRC}/liboath/gtk-doc/Makefile.in
.endif

.if !defined(NOPORTDOCS)
post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	${MKDIR} ${DOCSDIR}/pam_oath
	${INSTALL_DATA} ${WRKSRC}/pam_oath/README ${DOCSDIR}/pam_oath/
.endif

.include <bsd.port.mk>
