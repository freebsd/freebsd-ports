# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.2.0.a.2002080400
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux
PKGNAMESUFFIX=	-gui-gtk
DISTFILES=	ed2k_gui-${PORTVERSION}.freebsd-stable-i386.gz
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	gnet.1:${PORTSDIR}/net/gnet
RUN_DEPENDS=	donkey:${PORTSDIR}/net/edonkey-core

ONLY_FOR_ARCHS=	i386
XFREE86_VERSION=	4
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DOC_VERSION=	0.2.0.a.2002061600

BINARY_NAME=	ed2k_gui
DOC_FILES=	faq.html faq_german.html

.ifndef(NOPORTDOCS)
DISTFILES+=	ed2k_gui-${DOC_VERSION}.doc.tar.gz
.endif

post-extract:
.ifndef(NOPORTDOCS)
	@cd ${WRKSRC} && ${TAR} xzf \
		${DISTDIR}/ed2k_gui-${DOC_VERSION}.doc.tar.gz
.endif
	@${GZCAT} ${DISTDIR}/ed2k_gui-${PORTVERSION}.freebsd-stable-i386.gz \
		> ${WRKSRC}/${BINARY_NAME}

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
.endfor
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin
	@${LN} -s ${BINARY_NAME} ${PREFIX}/bin/edonkey-gui-gtk

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 450006 || ${OSVERSION} >= 500000
BROKEN=	"only available for 4.X-STABLE (post 4.6 Release)"
.endif

.include <bsd.port.post.mk>
